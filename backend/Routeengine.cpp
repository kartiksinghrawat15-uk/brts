#include "Routeengine.h"
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>

Routeengine::Routeengine()
{
    initializeRoutes();
}

void Routeengine::initializeRoutes() {

    vector<BusConnection> connections = {
        {"MP_NAGAR", "BHADBHADA", 10, 20},
        {"MP_NAGAR", "AIIMS", 4, 12}, {"MP_NAGAR", "BHOPAL_ISBT", 2, 5}, {"MP_NAGAR", "NEW_MARKET", 4, 12},
        {"MP_NAGAR", "BHADBHADA", 10, 20}, {"MP_NAGAR", "RANI_KAMLAPATI_RAILWAY_STN", 1 , 3}, {"MP_NAGAR", "DOORDARSHAN_KENDRA", 6 , 12},
        {"MP_NAGAR", "BHADBHADA", 10, 20}, {"MP_NAGAR", "BHADBHADA", 10, 20}, {"MP_NAGAR", "BAIRAGARH", 15, 30},
        {"MP_NAGAR", "KOHEFIZA", 9, 20},
        {"MP_NAGAR", "VIT_BHOPAL", 74, 130}, {"MP_NAGAR", "BHADBHADA", 10, 20},{"MP_NAGAR", "BHADBHADA", 10, 20},{"MP_NAGAR", "BHADBHADA", 10, 20},{"MP_NAGAR", "BHADBHADA", 10, 20},
        {"MP_NAGAR", "BHADBHADA", 10, 20}, {"MP_NAGAR", "BHADBHADA", 10, 20}, {"MP_NAGAR", "BHADBHADA", 10, 20},
    };
    for(const auto& conn : connections){
        //forward connection
        Edge fe = {conn.dest, conn.dist, conn.time};
        g[conn.src].push_back(fe);
        
        //backward connection
        Edge be = {conn.src, conn.dist, conn.time};
        g[conn.dest].push_back(be);
    }

    vector<string> bus1 = {"LALGHATI" , "BH0PAL_ISBT" , "AIIMS" , "NADRA_BUS_STAND" , "HAMIDIA_HOSPITAL" , "BAIRAGARH" , "MP_NAGAR" , "SONAGIRI" , "AWADHPURI" , "ARERA_COLONY" , "TT_NAGAR" , "BHEL" , "RAJA_BHOJ_AIRPORT" } ;
    vector<string> bus2 = {"RANI_KAMLAPATI_RAILWAY_STN" , "BHOPAL_ISBT" , "AIIMS" , "BHOPAL_JN" , "BAIRAGARH_RAILWAY_STN" , "NADRA_BUS_STAND" ,"LALGHATI" , "RAJA_BHOJ_AIRPORT" };
    vector<string> bus3 = {"KOHEFIZA" , "POLYTECHNIC" , "DOORDARSHAN_KENDRA" , "SHYAMALA_HILLS" , "AIIMS" , "NEW_MARKET" , "DB_CITY_MALL" , "PEOPLE_MALL" , "BHEL" } ;
    vector<string> bus4 = {"BAIRAGARH" , "BHOPAL_MILITARY_STN" , "EME" , "BAIRAGARH_RAILWAY_STN" , "BHOPAL_ISBT" , "AIIMS" , "RAJA_BHOJ_AIRPORT" , "BHOPAL_JN"};
    vector<string> bus9 = {"Rani_Kamlapati_Railway_STN", "BHOPAL_ISBT" , "ARERA_COLONY", "MP_NAGAR" , "BHOPAL_JN" , "NEHRU_NAGAR" , "BHEL" , "RAJA_BHOJ_AIRPORT" } ;
    vector<string> bus13 = {"SHAURYA_SMARAK_BHOPAL" , "BHOPAL_ISBT" , "SAIR_SAPATA_BHOPAL" , "INDIRA_GANDHI_RASHTRIYA_MANAV_SANGRAHALAYA" , "BIRLA_MUSEUM", "LAKE_VIEW_POINT" , "RMNH" , "STATE_MUSEUM_BHOPAL" , "RANI_KAMLAPATI_MAHAL" , "RAJA_BHOJ_STATUE" } ;
    vector<string> bus14 = {"LALGHATI" , "BHOPAL_ISBT" , "NADRA_BUS_STAND" , "BHOJPUR_MANDIR" , "BHIMBETIKA" , "SANCHI_STUPA" , "SALKANPUR_MANDIR" } ;
    vector<string> bus5 = {"BHOPAL_ISBT" , "INDORE_ISBT" , "SEHORE" , "VIT_BHOPAL" , "UJJAIN_ISBT" , "DEWAS_ISBT" };
    vector<string> bus7 = {"BHOPAL_ISBT" , "RANI_KAMLAPATI_RAILWAY_STATION" , "BHOPAL_JN" , "BHADBHADA" , "BHOJPUR" , "BHIMBETIKA" , "SALKANPUR" , "SEHORE_ISBT" };
    vector<string> bus8 = {"BHOPAL_ISBT" , "HAMIDIA_HOSPITAL" ,"AIIMS" , "CHIRAYU_HOSPITAL" ,  "ARERA_COLONY" , "TT_NAGAR" , "NEHRU_NAGAR"};
    vector<string> bus6 = {"BHOPAL_ISBT" , "VIDISHA_ISBT" , "SAGAR_ISBT" , "JABALPUR_ISBT" , "RAISEN_ISBT" , "SANCHI"};
    vector<string> bus10 = {"LALGHATI" , "ASHOKA_GARDEN" , "SONAGIRI" , "PANCHSHEEL_NAGAR" , "GOVINDPURA" , "BAGGSEWANIYA" , "AWADHPURI" , "NEELBAD" ,  "SHYAMALA_HILLS" , "SAIR_SAPATA_BHOPAL" , "NEHRU_NAGAR" , "SHIVAJI_NAGAR" , "CHARR_IMLI" , };
    vector<string> bus12 = {"LALGHATI" , "ASHOKA_GARDEN" ,"PANCHSHEEL_NAGAR" , "SONAGIRI" , "GOVINDPURA" , "BAGGSEWANIYA" , "AWADHPURI" , "NEELBAD" ,  "SHYAMALA_HILLS" , "SAIR_SAPATA_BHOPAL" , "NEHRU_NAGAR" , "SHIVAJI_NAGAR" , "CHARR_IMLI" ,  };
    vector<string> bus11 = {"BHOPAL_ISBT" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STN" , "VIDYA_NAGAR" , ""} ; 
    vector<string> bus24 = {"INDORE_ISBT" ,"DEWAS_ISBT" ,"VIT_BHOPAL" ,"AMLAHA" , "SEHORE" , "BHOPAL_ISBT" } ; 
    vector<string> bus25 = { "SAGAR_ISBT", "JABALPUR_ISBT","VIDISHA_ISBT","BHOPAL_ISBT" , "BHOPAL_JN", "RANI_KAMLAPATI_RAILWAY_STN" } ; 
    vector<string> bus15 = {"ARERA_COLONY" , "MP_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STN" , "VIDYA_NAGAR" , "BHOPAL_JN" , "LALGHATI" , "NADRA_BUS_STAND"} ; 
    vector<string> bus16 = {"MP_NAGAR" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "AIIMS" , "HAMIDIA_HOSPITAL" , "CHIRAYU_HOSPITAL"} ; 
    vector<string> bus17 = {"BHOPAL_JN" , "RANI_KAMLAPATI_RAILWAY_STN" , "AIIMS" , "EME", "BHOPAL_MILITARY_STN" , "BAIRAGARH" , "BHOPAL_ISBT" , ""} ; 
    vector<string> bus18 = {"MP_NAGAR" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "VIDYA_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STN" , "LALGHATI" , "NADRA_BUS_STAND" , "" } ; 
    vector<string> bus19 = {"ASHOKA_GARDEN" , "SONAGIRI", "NEHRU_NAGAR" , "CHARR_IMLI" , "GOVINDPURA" , "SHASTRI_NAGAR", "NEHRU_NAGAR" , "PANCHSHEEL_NAGAR" , "RANI_KAMLAPATI_RAILWAY_STN" , "VIDYA_NAGAR" , "LALGHATI" , "NADRA_BUS_STAND"} ; 
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

    Routes = {bus1, bus2, bus3, bus4, bus5, bus30, bus31, bus32, bus20, bus21, bus22, bus23, bus24, bus25, bus26, bus27, bus28, bus29, bus17, bus10, bus13 , bus11,bus12,bus14,bus15,bus16,bus18,bus19,bus6,bus7,bus8,bus9,bus10,bus10,bus10,bus10,};
}
vector<string> Routeengine::uniquestn(){
    if(Routes.empty()){
        initializeRoutes();
    }
    set<string> allstn;
    for(const auto& busl:Routes){
        for(const auto& st:busl){
            allstn.insert(st);
        }
    }

    return vector<string>(allstn.begin(), allstn.end());
}

string Routeengine::findRoute(string source, string destination) {
    string result;

    // 1. Only check if source exists as an outgoing key. 
    // Destination might be the end of a route, so we don't strictly check g.find(destination)
    if (g.find(source) == g.end()) {
        return "ERROR: SOURCE STATION NOT FOUND IN NETWORK";
    }

    queue<string> q;
    unordered_map<string, string> par;
    unordered_map<string, bool> vis;
    unordered_map<string, int> dist_to;
    unordered_map<string, int> time_to;

    q.push(source);
    vis[source] = true;
    dist_to[source] = 0;
    time_to[source] = 0;
    bool found = false;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (curr == destination) {
            found = true;
            break;
        }

        for (const auto& edge : g[curr]) {
            string n1 = edge.des;
            if (!vis[n1]) {
                vis[n1] = true;
                par[n1] = curr;
                dist_to[n1] = dist_to[curr] + edge.dis;
                time_to[n1] = time_to[curr] + edge.time;
                q.push(n1);
            }
        }
    }

    if (!found) {
        return "ROUTE NOT FOUND BETWEEN THESE TWO POINTS";
    }

    // Backtrack to find path
    vector<string> path;
    string curr_node = destination;
    while (curr_node != source) {
        path.push_back(curr_node);
        curr_node = par[curr_node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());

    // Build the output path string
    result = "ROUTE: ";
    for (size_t i = 0; i < path.size(); ++i) {
        result += path[i];
        if (i < path.size() - 1) {
            result += " -> ";
        }
    }

    // Append total metrics so your Node server and Webpage can parse/display them!
    result += "\nDISTANCE: " + to_string(dist_to[destination]);
    result += "\nTIME: " + to_string(time_to[destination]);

    return result; // Crucial fix: return the final string
}


