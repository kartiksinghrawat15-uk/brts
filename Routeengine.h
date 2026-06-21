
#ifndef ROUTEENGINE_H
#define ROUTEENGINE_H

#include <vector>
#include <string>
#include <map>

using namespace std;

struct Edge
{
    string des ;
    int dis ;
    int time ;
};

class Routeengine
{
public:

    Routeengine();

    string findRoute(string source, string destination);

private:

    vector<vector<string>> Routes;
    map<string, vector<Edge>> g ; 

    void initializeRoutes();
};

#endif