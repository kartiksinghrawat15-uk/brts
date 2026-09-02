#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Routeengine.h"
#include <string>
#include <vector>
using namespace std;

string dropdown(const string& pro, const vector<string>& op); 


class Result;

class Mainwindow
{

public:
    Mainwindow();
    ~Mainwindow() ;

    void findRoute() ;

private :
    void on_pb_1_clicked();

private:
    Result* result;
    Routeengine engine ;

};
#endif
