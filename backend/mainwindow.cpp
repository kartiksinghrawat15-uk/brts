#include "mainwindow.h"
#include <string>
#include "Routeengine.h"
#include <iostream>
#include <conio.h>
#include <set>

string dropdown(const string& pro, const vector<string>& option){
    int selin = 0;
    int numop = option.size();
    while(true){
        system("cls");
        cout << "USE  UP/DOWN TO NAVIGATE FURTHER " << endl;
        cout << "----------------------------------------------------------" ;
        for(int i = 0 ; i < numop ; ++ i){
            if( i == selin){
                cout << " ==> [ " << option[i] << " ] <==\n";

            }
            else{
                cout << "    " << option[i] << "\n";
            }

        }
        cout << "\n------------------------------------------------\n";
        int inputkey = _getch();
        if(inputkey == 224){
            int arrowkey = _getch();
            if(arrowkey == 72){
                selin = ( selin - 1 + numop) % numop;
            }else if(arrowkey == 80){
                selin = (selin + 1 ) % numop ;
            }
        }else if (inputkey == 13 ){
            return option[selin];
        }

    }
}

int main(){
    Routeengine engine;
    engine.initializeRoutes();
    set<string>unique_stops_set(engine.uniquestn().begin(), engine.uniquestn().end());

    string st = dropdown("SELECT YOUR SOURCE : ", vector<string>(unique_stops_set.begin(), unique_stops_set.end()));
    string en = dropdown("SELECT YOUR DESTINATION :", vector<string>(unique_stops_set.begin(), unique_stops_set.end())); 

}



