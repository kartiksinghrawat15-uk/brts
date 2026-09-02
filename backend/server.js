const express = require('express');
const { execFile } = require('child_process');
const path = require('path');
const session = require('express-session');

const {
    registerUser,
    loginUser
} = require('./auth');

const app = express();
app.use(express.json());

app.use(session({
    secret: 'brts-secret-key',
    resave: false,
    saveUninitialized: false,
    cookie: {
        maxAge: 1000 * 60 * 60 * 24
    }
}));

// const app = express();


// ==========================================
// FRONTEND
// ==========================================

const frontendPath =
    path.join(__dirname, '../frontend/html');

app.use(express.static(frontendPath));


// ==========================================
// HOME PAGE
// ==========================================

app.get('/', (req, res) => {

    res.sendFile(
        path.join(frontendPath, 'index.html')
    );

});


// ==========================================
// GET STATIONS
// ==========================================

app.get('/api/stations', (req, res) => {

    const binaryPath =
        path.join(__dirname, 'main.exe');


    execFile(
        binaryPath,
        ['--stations'],
        { cwd: __dirname },

        (error, stdout, stderr) => {

            if (error) {

                console.error(
                    "C++ STATION ERROR:",
                    error
                );

                console.error(
                    "STDERR:",
                    stderr
                );

                return res.status(500).json({
                    error: "Failed to run C++"
                });
            }


            try {

                const stations =
                    JSON.parse(stdout.trim());

                console.log(
                    "STATIONS:",
                    stations
                );

                res.json(stations);

            }
            catch (err) {

                console.error(
                    "STATION JSON ERROR:",
                    err
                );

                console.error(
                    "C++ OUTPUT:",
                    stdout
                );

                res.status(500).json({
                    error: "Invalid station JSON"
                });
            }

        }
    );

});


// ==========================================
// FIND ROUTE
// ==========================================

app.get('/api/route', (req, res) => {

    const source = req.query.source;
    const destination = req.query.destination;


    if (!source || !destination) {

        return res.status(400).json({
            error:
                "Source and destination are required"
        });

    }


    console.log(
        "REQUESTED ROUTE:",
        source,
        "→",
        destination
    );


    const binaryPath =
        path.join(__dirname, 'main.exe');


    execFile(

        binaryPath,

        [
            '--route',
            source,
            destination
        ],

        { cwd: __dirname },

        (error, stdout, stderr) => {

            if (error) {

                console.error(
                    "C++ ROUTE ERROR:",
                    error
                );

                console.error(
                    "STDERR:",
                    stderr
                );

                return res.status(500).json({
                    error:
                        "C++ route engine failed"
                });

            }


            console.log(
                "C++ ROUTE OUTPUT:"
            );

            console.log(stdout);


            // ==================================
            // PARSE ROUTE
            // ==================================

            const output =
                stdout.trim();


            if (
                output.startsWith("ERROR:") ||
                output.startsWith("ROUTE NOT FOUND")
            ) {

                return res.status(404).json({
                    error: output
                });

            }


            // ==================================
            // Extract ROUTE
            // ==================================

            const routeMatch =
                output.match(/ROUTE:\s*(.*)/);

            // ==================================
            // Extract DISTANCE
            // ==================================

            const distanceMatch =
                output.match(/DISTANCE:\s*(\d+)/);


            // ==================================
            // Extract TIME
            // ==================================

            const timeMatch =
                output.match(/TIME:\s*(\d+)/);


            if (
                !routeMatch ||
                !distanceMatch ||
                !timeMatch
            ) {

                console.error(
                    "Could not parse C++ output"
                );

                return res.status(500).json({
                    error:
                        "Invalid route output from C++",
                    output: output
                });

            }


            const route =
                routeMatch[1]
                    .split(" -> ")
                    .map(station => station.trim());


            const distance =
                Number(distanceMatch[1]);


            const time =
                Number(timeMatch[1]);


            // ==================================
            // SEND JSON TO FRONTEND
            // ==================================

            res.json({

                source: source,

                destination: destination,

                route: route,

                distance: distance,

                time: time

            });

        }

    );

});

app.post('/api/register', async (req, res) => {

    const { name, email, password } = req.body;

    if (!name || !email || !password) {
        return res.status(400).json({
            error: 'All fields are required'
        });
    }

    try {

        const user = await registerUser(
            name,
            email,
            password
        );

        res.json({
            message: 'Registration successful',
            user: user
        });

    } catch (error) {

        res.status(400).json({
            error: error.message
        });
    }
});

app.post('/api/login', async (req, res) => {

    const { email, password } = req.body;

    if (!email || !password) {
        return res.status(400).json({
            error: 'Email and password are required'
        });
    }

    try {

        const user = await loginUser(
            email,
            password
        );

        req.session.user = user;

        res.json({
            message: 'Login successful',
            user: user
        });

    } catch (error) {

        res.status(401).json({
            error: error.message
        });
    }
});

app.post('/api/logout', (req, res) => {

    req.session.destroy((err) => {

        if (err) {
            return res.status(500).json({
                error: 'Logout failed'
            });
        }

        res.json({
            message: 'Logout successful'
        });
    });
});

// ==========================================
// START SERVER
// ==========================================

app.listen(3000, () => {

    console.log(
        "================================"
    );

    console.log(
        "🚍 BRTS SERVER RUNNING"
    );

    console.log(
        "http://localhost:3000"
    );

    console.log(
        "================================"
    );

});