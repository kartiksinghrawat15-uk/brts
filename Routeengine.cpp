#include "Routeengine.h"
Routeengine::Routeengine()
{
    initializeRoutes();
}

void Routeengine::initializeRoutes() {

g["MP_NAGAR"].push_back({"AIIMS",11,22});
g["EME"].push_back({"MP_NAGAR",5,10});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});

g["BHOPAL_JN"].push_back({"EME",1,2});
g["HAMIDIA_HOSPITAL"].push_back({"MP_NAGAR",11,22});
g["AIIMS"].push_back({"RAJA_BHOJ_AIR",1,2});
g["EME"].push_back({"HAMIDIA_HOSPITAL",1,2});

g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["MP_NAGAR"].push_back({"BHOPAL_JN",1,2});
g["BHOPAL_ISBT"].push_back({"INDORE_ISBT",200,350});

g["MP_NAGAR"].push_back({"RAJA_BHOJ_AIRPORT",7,10});
g["MP_NAGAR"].push_back({"RANI_KAMLAPATI_RAILWAY_STATION",10,20});
g["MP_NAGAR"].push_back({"BAIRAGARH",10,20});
g["MP_NAGAR"].push_back({"EME",7,12});
g["MP_NAGAR"].push_back({"BHOPAL_MILITARY_STN",10,20});
g["MP_NAGAR"].push_back({"ARERA_COLONY",6,15});
g["MP_NAGAR"].push_back({"NEHRU_NAGAR",10,20});
g["MP_NAGAR"].push_back({"ISBT",10,20});
g["MP_NAGAR"].push_back({"RAISEN_ISBT",10,20});
g["MP_NAGAR"].push_back({"SANCHI_STUPA",10,20});
g["MP_NAGAR"].push_back({"SHYAMALA_HILLS",10,20});
g["MP_NAGAR"].push_back({"LALGHATI",10,20});
g["MP_NAGAR"].push_back({"BHEL",10,20});
g["MP_NAGAR"].push_back({"ASHOKA_GARDEN",10,20});
g["MP_NAGAR"].push_back({"SEHORE",10,20});
g["MP_NAGAR"].push_back({"VIT_BHOPAL",10,20});
g["MP_NAGAR"].push_back({"INDORE_ISBT",10,20});
g["MP_NAGAR"].push_back({"STATE_MUSEUM_BHOPAL",10,20});
g["MP_NAGAR"].push_back({"SAGAR_ISBT",10,20});
g["MP_NAGAR"].push_back({"JABALPUR_ISBT",10,20});
g["MP_NAGAR"].push_back({"VIDHISHA_ISBT",10,20});
g["MP_NAGAR"].push_back({"DEWAS_ISBT",10,20});
g["MP_NAGAR"].push_back({"PANCHSHEEL_NAGAR",10,20});
g["MP_NAGAR"].push_back({"TT_NAGAR",10,20});
g["MP_NAGAR"].push_back({"POLYTECHNIC",10,20});
g["MP_NAGAR"].push_back({"DORDHARSHAN_KENDRA",10,20});
g["MP_NAGAR"].push_back({"BHIMBETIKA",10,20});
g["MP_NAGAR"].push_back({"BHOJPUR",10,20});
g["MP_NAGAR"].push_back({"BHOJPUR_MANDIR",10,20});
g["LALGHATI"].push_back({"SONAGIRI",11,22});

g["MP_NAGAR"].push_back({"SONAGIRI",10,20});
g["MP_NAGAR"].push_back({"CHIRAYU_HOSPITAL",10,20});
g["MP_NAGAR"].push_back({"NADRA_BUS_STAND",10,20});
g["MP_NAGAR"].push_back({"HAMIDIA_HOSPITAL",10,20});
g["MP_NAGAR"].push_back({"ASTHA",10,20});
g["MP_NAGAR"].push_back({"AWADHPURI",10,20});
g["MP_NAGAR"].push_back({"GOVINDPURA",10,20});
g["MP_NAGAR"].push_back({"SHASTRI_NAGAR",10,20});
g["MP_NAGAR"].push_back({"BAGGESEWANIA",10,20});
g["MP_NAGAR"].push_back({"CHAR_IMLI",10,20});
g["MP_NAGAR"].push_back({"SAIR_SAPATA",10,20});

g["MP_NAGAR"].push_back({"KOHEFIZA",10,20});
g["MP_NAGAR"].push_back({"BHADBHADA",10,20});
g["MP_NAGAR"].push_back({"INDIRA_GANDHI_RASHTRIYA_MANAV_SANGRAHALAYA",10,20});
g["MP_NAGAR"].push_back({"UJJAIN_ISBT",10,20});
g["MP_NAGAR"].push_back({"RAJA_BHOJ_STATUE",10,20});
g["MP_NAGAR"].push_back({"BIRLA_MUSEUM",10,20});
g["MP_NAGAR"].push_back({"LAKE_VIEW_POINT",10,20});
g["MP_NAGAR"].push_back({"CHIRAYU_HOSPITAL",10,20});
g["NEHRU_NAGAR"].push_back({"ARERA_COLONY",15,24});
g["MP_NAGAR"].push_back({"NEELBAD",10,20});

    // storing bus routes ;
    // vector<vector<string>> Routes ;
    vector<string> bus1 = {"LALGHATI" , "BH0PAL_ISBT" , "AIIMS" , "NADRA_BUS_STAND" , "HAMIDIA_HOSPITAL" , "BAIRAGARH" , "MP_NAGAR" , "SONAGIRI" , "AWADHPURI" , "ARERA_COLONY" , "TT_NAGAR" , "BHEL" , "RAJA_BHOJ_AIRPORT" } ;
    vector<string> bus2 = {"RANI_KAMLAPATI_RAILWAY_STN" , "BHOPAL_ISBT" , "AIIMS" , "BHOPAL_JN" , "BAIRAGARH_RAILWAY_STN" , "NADRA_BUS_STAND" ,"LALGHATI" , "RAJA_BHOJ_AIRPORT" };
    vector<string> bus3 = {"KOHEFIZA" , "POLYTECHNIC" , "DOORDARSHAN_KENDRA" , "SHYAMALA_HILLS" , "AIIMS" , "NEW_MARKET" , "DB_CITY_MALL" , "PEOPLE_MALL" , "BHEL" } ;
    vector<string> bus4 = {"BAIRAGARH" , "BHOPAL_MILITARY_STN" , "EME" , "BAIRAGARH_RAILWAY_STATION" , "BHOPAL_ISBT" , "AIIMS" , "RAJA_BHOJ_AIR" , "BHOPAL_JN"};
    vector<string> bus9 = {"Rani_Kamlapati_Railway_STN", "BHOPAL_ISBT" , "ARERA_COLONY ", "MP_NAGAR" , "BHOPAL_JN" , "NEHRU_NAGAR" , "BHEL" , "RAJA_BHOJ_AIRPORT" } ;
    vector<string> bus13 = {"SHAURYA_SMARAK_BHOPAL" , "BHOPAL_ISBT" , "SAIR_SAPATA_BHOPAL" , "INDIRA_GANDHI_RASHTRIYA_MANAV_SANGRAHALAYA" , "BIRLA_MUSEUM", "LAKE_VIEW_POINT" , "RMNH" , "STATE_MUSEUM_BHOPAL" , "RANI_KAMLAPATI_MAHAL" , "RAJA_BHOJ_STATUE" } ;
    vector<string> bus14 = {"LALGHATI" , "BHOPAL_ISBT" , "NADRA_BUS_STAND" , "BHOJPUR_MANDIR" , "BHIMBETIKA" , "SANCHI_STUPA" , "SALKANPUR_MANDIR" } ;
    vector<string> bus5 = {"BHOPAL_ISBT" , "INDORE_ISBT" , "SEHORE" , "VIT_BHOPAL" , "UJJAIN_ISBT" , "DEWAS_ISBT" };
    vector<string> bus7 = {"BHOPAL_ISBT" , "RANI_KAMLAPATI_RAILWAY_STATION" , "BHOPAL_JN" , "BHADBHADA" , "BHOJPUR" , "BHIMBETIKA" , "SALKANPUR" , "SEHORE_ISBT" };
    vector<string> bus8 = {"BHOPAL_ISBT" , "HAMIDIA_HOSPITAL" ,"AIIMS" , "CHIRAYU_HOSPITAL" ,  "ARERA_COLONY" , "TT_NAGAR" , "NEHRU_NAGAR"};
    vector<string> bus6 = {"BHOPAL_ISBT" , "VIDISHA_ISBT" , "SAGAR_ISBT" , "JABALPUR_ISBT" , "RAISEN_ISBT" , "SANCHI"};
    vector<string> bus10 = {"LALGHATI" , "ASHOKA_GARDEN" , "SONAGIRI" , "PANCHSHEEL_NAGAR" , "GOVINDPURA" , "BAGGSEWANIYA" , "AWADHPURI" , "NEELBAD" ,  "SHYAMALA_HILLS" , "SAIR_SAPATA_BHOPAL" , "NEHRU_NAGAR" , "SHIVAJI_NAGAR" , "CHARR_IMLI" , };
    vector<string> bus12 = {"LALGHATI" , "ASHOKA_GARDEN" ,"PANCHSHEEL_NAGAR" , "SONAGIRI" , "GOVINDPURA" , "BAGGSEWANIYA" , "AWADHPURI" , "NEELBAD" ,  "SHYAMALA_HILLS" , "SAIR_SAPATA_BHOPAL" , "NEHRU_NAGAR" , "SHIVAJI_NAGAR" , "CHARR_IMLI" ,  };
    vector<string> bus11 = {"BHOPAL_ISBT" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STATON" , "VIDYA_NAGAR" , ""} ; 
    vector<string> bus24 = {"INDORE_ISBT" ,"DEWAS_ISBT" ,"VIT_BHOPAL" ,"AMLAHA" , "SEHORE" , "BHOPAL_ISBT" } ; 
    vector<string> bus25 = { "SAGAR_ISBT", "JABALPUR_ISBT","VIDISHA_ISBT","BHOPAL_ISBT" , "BHOPAL_JN", "RANI_KAMLAPATI_RAILWAY_STATION" } ; 
    vector<string> bus15 = {"ARERA_COLONY" , "MP_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STN" , "VIDYA_NAGAR" , "BHOPAL_JN" , "LALGHATI" , "NADRA_BUS_STAND"} ; 
    vector<string> bus16 = {"MP_NAGAR" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "AIIMS" , "HAMIDIA_HOSPITAL" , "CHIRAYU_HOSPITAL"} ; 
    vector<string> bus17 = {"BHOPAL_JN" , "RANI_KAMLAPATI_RAILWAY_STN" , "AIIMS" , "EME", "BHOPAL_MILITARY_STATION" , "BAIRAGARH" , "BHOPAL_ISBT" , ""} ; 
    vector<string> bus18 = {"MP_NAGAR" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "VIDYA_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STN" , "LALGHATI" , "NADRA_BUS_STAND" , "" } ; 
    vector<string> bus19 = {"ASHOLA_GARDEN" , "SONAGIRI", "NEHRU_NAGAR" , "CHAR_IMLI" , "GOVINDPURA" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STN" , "VIDYA_NAGAR" , "LALGHATI" , "NADRA_BUS_STAND"} ; 
    vector<string> bus20 = {"BHEL" , "PEOPLE_MALL", "DB_CITY_MALL" , "NEW_MARKET" , "AIIMS" , "SHYMALA_HILLS" , "DOORDARSHAN_KENDRA" , "POLYTECHNIC" , "KOHEFIZA"} ; 
    vector<string> bus21 = {"RAJA_BHOJ_AIRPORT" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STN" , "VIDYA_NAGAR" , "LALGHATI"} ; 
    vector<string> bus22 = {"RAJA_BHOJ_AIRPORT" , "LALGHATI", "NADRA_BUS_STAND" , "BHOPAL_ISBT" , "RANI_KAMLAPATI_RAILWAY_STN"} ; 
    vector<string> bus23 = {"BHOPAL_ISBT" , "RAJA_BHOJ_AIRPORT", "LALGHATI" , "NADRA_BUS_STAND" , "RANI_KAMLAPATI_RAILWAY_STN" , "BHOPAL_JN" , ""} ; 
    vector<string> bus27 = {"NEW_MARKET" , "", "NADRA_BUS_STAND" , "BHOPAL_ISBT" , "RANI_KAMLAPATI_RAILWAY_STN"} ; 
    vector<string> bus26 = {"BHOPAL_ISBT" , "JABALPUR_ISBT" , "GWALIOR_ISBT" , "KANPUR_ISBT" , "LUCKNOW_ISBT" , "MERRUT_ISBT" , "AGRA_ISBT" , "NEW_DELHI_ISBT" , "CHANDIGARH_ISBT" , "SRINAGAR_ISBT" , "LEH_ISBT"} ;
    vector<string> bus28 = {"LEH_ISBT" , "SRINAGAR_ISBT" , "CHANDIGARH_ISBT" , "NEW_DELHI_ISBT" , "AGRA_ISBT" , "MERRUT_ISBT" , "LUCKNOW_ISBT" , "KANPUR_ISBT" , "GWALIOR_ISBT" , "JABALPUR_ISBT" , "BHOPAL_ISBT"} ;
    vector<string> bus29 = {"BHOPAL_ISBT" , "HOSHANGABAD_ISBT" , "BETUL_ISBT" , "AMRAVATI_ISBT" ,"CHHATRAPATI_SAMBHAJINAGAR_ISBT" , "NASHIK_ISBT" , "AHILYANAGAR_ISBT" , "MUMBAI_ISBT" , "PUNE_ISBT" , "SATARA_ISBT" , "KOLHAPUR_ISBT" , "BELGAVI_ISBT" , "HUBBALI_ISBT" , "HAMPI_ISBT" , "BALLARI_ISBT" ,  "BANGLORE_ISBT" , "MYSURU_ISBT" ,"OOTY_ISBT" , "COIMBATORE_ISBT" , "PALAKKAD_ISBT" , "THRISSUR_ISBT" ,"KOCHI_ISBT" , "KUMARAKOM_ISBT" , "KOLLAM_ISBT" , "THIRUVANANTHAPURAM_ISBT" , "NAGERCOIL_ISBT" , "KANNIYAKUMARI_ISBT" } ;
    vector<string> bus31 = {"KANNIYAKUMARI_ISBT" , "NAGARCOIL_ISBT" , "THIRUVANANTHAPURAM_ISBT" , "KOLLAM_ISBT" , "KUMARAKOM_ISBT" , "KOCHI_ISBT" , "THISSUR_ISBT" , "PALAKKAD_ISBT" , "COIMBATORE_ISBT" , "OOTY_ISBT" , "MYSURU_ISBT" , "BANGLORE_ISBT" , "BALLARI_ISBT" , "HAMPI_ISBT" , "HUBBALI_ISBTT" , "BELGAVI_ISBT" , "KOLHAPUR_ISBT" , "SATARA_ISBT" , "PUNE_ISBT" , "MUMBAI_ISBT" , "AHILYANAGAR_ISBT" , "NASHIK_ISBT" , "CHHATRAPATI_SAMBHAJINAGAR_ISBT" , "AMRAVATI_ISBT" , "BETUL_ISBT" , "HOSHANGABAD_ISBT" , "BHOPAL_ISBT" } ;
    vector<string> bus32 = {"BHOPAL_ISBT" , "SEHORE", "DEWAS_ISBT" , "INDORE_ISBT" , "MHOW_ISBT" , "VADODARA_ISBT" , "AHEMDABAD_ISBT" , "GANDHINAGAR_ISBT" , "SOMNATH_ISBT"} ; 
    vector<string> bus30 = {"RAJA_BHOJ_STATUE" , "RANI_KAMLAPATI_MAHAL" , "STATE_MUSEUM_BHOPAL" , "RMNH" , "LAKE_VIEW_POINT" , "BIRLA_MUSEUM" , "INDIRA_GANDHI_RASHTRIYA_MANAV_SANGRAHALAYA" , "SAIR_SAPATA_BHOPAL" , "BHOPAL_ISBT" , "SHAURYA_SMARAK_BHOPAL"} ;


    Routes.push_back(bus1);
    Routes.push_back(bus2);
    Routes.push_back(bus3);
    Routes.push_back(bus4);
    Routes.push_back(bus5);
    Routes.push_back(bus6);
    Routes.push_back(bus7);
    Routes.push_back(bus8);
    Routes.push_back(bus9);
    Routes.push_back(bus10);
    Routes.push_back(bus11);
    Routes.push_back(bus12);
    Routes.push_back(bus13);
    Routes.push_back(bus14);
    Routes.push_back(bus15);
    Routes.push_back(bus16);
    Routes.push_back(bus17);
    Routes.push_back(bus18);
    Routes.push_back(bus19);
    Routes.push_back(bus20);
    Routes.push_back(bus21);
    Routes.push_back(bus22);
    Routes.push_back(bus23);
    Routes.push_back(bus24);
    Routes.push_back(bus25);
    Routes.push_back(bus26);
    Routes.push_back(bus27);
    Routes.push_back(bus28);
    Routes.push_back(bus29);
    Routes.push_back(bus30);
    Routes.push_back(bus31);
    Routes.push_back(bus32);
}

string Routeengine::findRoute(string source, string destination){
        int total_dis = 0 ;
        int total_time = 0 ;
        vector<vector<string>> Routes;
    map<string, vector<Edge>> g ; 
        string result ;

        for (int i = 0; i < Routes.size(); i++) {

            bool sourceFound = false;
            bool destinationFound = false;

            for (int j = 0; j < Routes[i].size(); j++) {
                if (Routes[i][j] == source) {
                    sourceFound = true;
                }
                if (sourceFound && Routes[i][j] == destination) {
                    destinationFound = true;
                }

            }
            if (sourceFound && destinationFound) {
                // cout << "Route Found: " << endl;
                // cout << endl;
                // cout << "Your Bus number for this route is - > " << i+1 ; 
                // cout << endl;
                // cout << "Your Bus path is : " ;

                for (int j = 0; j < Routes[i].size(); j++) {
                    result += Routes[i][j] ;
                    result += " -> " ;

                    // cout << endl;

                    string curr = Routes[i][j] ;
                    string next = Routes[i][j+1] ;

                    for(auto x : g[curr]) {
                        if (x.des == next ){

                            // cout << "Destination: " << x.des << endl;
                            total_dis = total_dis + x.dis ;
                            return to_string(total_dis);
                            total_time = total_time + x.time ; 
                            return to_string(total_time);
                        }
                    }
                }
            }
        }

            for (int i = 0; i < Routes.size(); i++) {

            bool sourceFound = false;
            bool destinationFound = false;

            for (int j = 0; j < Routes[i].size(); j++) {
                if (Routes[i][j] == source) {
                    sourceFound = true;
                }
                if (sourceFound && Routes[i][j] == destination) {
                    destinationFound = true;
                }

            }
            if (sourceFound == false || destinationFound == false ){
                return "ROUTE NOT FOUND" ;
            }

    }
}