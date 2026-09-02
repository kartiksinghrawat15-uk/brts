const bcrypt = require('bcrypt');
const db = require('./db');

// REGISTER USER
function registerUser(name, email, password) {
    return new Promise(async (resolve, reject) => {

        try {
            // Hash password
            const passwordHash = await bcrypt.hash(password, 10);

            const sql = `
                INSERT INTO users (name, email, password_hash)
                VALUES (?, ?, ?)
            `;

            db.run(
                sql,
                [name, email, passwordHash],
                function (err) {

                    if (err) {
                        if (err.code === 'SQLITE_CONSTRAINT') {
                            return reject(
                                new Error('Email already registered')
                            );
                        }

                        return reject(err);
                    }

                    resolve({
                        id: this.lastID,
                        name: name,
                        email: email
                    });
                }
            );

        } catch (err) {
            reject(err);
        }
    });
}


// LOGIN USER
function loginUser(email, password) {
    return new Promise((resolve, reject) => {

        const sql = `
            SELECT * FROM users
            WHERE email = ?
        `;

        db.get(sql, [email], async (err, user) => {

            if (err) {
                return reject(err);
            }

            if (!user) {
                return reject(
                    new Error('Invalid email or password')
                );
            }

            const passwordMatch =
                await bcrypt.compare(
                    password,
                    user.password_hash
                );

            if (!passwordMatch) {
                return reject(
                    new Error('Invalid email or password')
                );
            }

            resolve({
                id: user.id,
                name: user.name,
                email: user.email
            });
        });
    });
}


module.exports = {
    registerUser,
    loginUser
};