#include <iostream>
using namespace std;
#include <LinkedQueue.h>

class Bus {
private:
    int id;
    string type;
    int capacity = 45;
    int maintenanceT; // for time
    int maintenanceJ; // for journeys
    LinkedQueue WBus; // for wheelchair
    LinkedQueue MBus; // for normal people

public:
    Bus(int id, string type, int maintenanceT, int maintenanceJ, LinkedQueue WBus, LinkedQueue MBus)
        : id(id), type(type), maintenanceT(maintenanceT), maintenanceJ(maintenanceJ), WBus(WBus), MBus(MBus) {}

    int getId() { return id; }
    string getType() { return type; }
    int getMaintenanceTime() { return maintenanceT; }
    int getMaintenanceJourneys() { return maintenanceJ; }
    LinkedQueue getWBus() { return WBus;}
    LinkedQueue getMBus() { return MBus;}


};