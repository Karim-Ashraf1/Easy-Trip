#include <iostream>
using namespace std;
class Bus {
private:
    int id;
    string type;
    int capacity;
    int maintenanceTime;
    int maintenanceJourneys;


public:
    Bus(int id, string type, int capacity, int maintenanceTime, int maintenanceJourneys)
        : id(id), type(type), capacity(capacity), maintenanceTime(maintenanceTime), maintenanceJourneys(maintenanceJourneys) {}

    int getId() { return id; }
    string getType() { return type; }
    int getCapacity() { return capacity; }
    int getMaintenanceTime() { return maintenanceTime; }
    int getMaintenanceJourneys() { return maintenanceJourneys; }
};