#include "Routeengine.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    Routeengine engine;

    // ==========================================
    // RETURN ALL STATIONS
    // ==========================================

    if (argc >= 2 && string(argv[1]) == "--stations")
    {
        vector<string> stations = engine.uniquestn();

        cout << "[";

        for (size_t i = 0; i < stations.size(); ++i)
        {
            cout << "\"" << stations[i] << "\"";

            if (i < stations.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]";
        return 0;
    }
    // ==========================================
    // FIND ROUTE
    // ==========================================

    if (argc >= 4 && string(argv[1]) == "--route")
    {
        string source = argv[2];
        string destination = argv[3];

        string result =
            engine.findRoute(source, destination);

        cout << result;

        return 0;
    }


    // ==========================================
    // INVALID COMMAND
    // ==========================================

    cout << "ERROR: Invalid command";

    return 1;
}
