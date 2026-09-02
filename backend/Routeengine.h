
#ifndef ROUTEENGINE_H
#define ROUTEENGINE_H
#include <string>
#include <vector>

#include <vector>
#include <string>
#include <map>

using namespace std;

struct Edge
{
    string des ;
    int dis ;
    int time ;
    string busname;
};

struct BusConnection
{
    string src ;
    string dest ;
    int dist ;
    int time ;
};

class Routeengine
{
public:

    Routeengine();

    string findRoute(string source, string destination);
    vector<string> uniquestn();
    void initializeRoutes();

private:

    vector<vector<string>> Routes;
    map<string, vector<Edge>> g ; 

};

#endif