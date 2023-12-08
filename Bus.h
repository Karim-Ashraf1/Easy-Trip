#include <iostream>
using namespace std;
class Bus {
private:
    int id;
    string type;
    int capacity = 40;
    int maintenanceT; // for time
    int maintenanceJ; // for journeys


public:
    Bus(int id, string type, int maintenanceT, int maintenanceJ)
        : id(id), type(type), maintenanceT(maintenanceT), maintenanceJ(maintenanceJ){}

    int getId() { return id; }
    string getType() { return type; }
    int getMaintenanceTime() { return maintenanceT; }
    int getMaintenanceJourneys() { return maintenanceJ; }


};