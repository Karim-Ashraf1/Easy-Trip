<<<<<<< HEAD

=======
#pragma once
>>>>>>> d9a6a53286efc62ae0faccdee840f0c3fbe99ac0
#include <iostream>
#include <LinkedQueue.h>
#include "Passenger.h"

class Bus {
private:
    int id;
    std::string type;
    int capacity = 45;
    int CurrentLoad;
    int maintenanceT; // for time
    int maintenanceJ; // for journeys
    Passenger PassengerInBus[];
public:
    Bus(int id, string type, int maintenanceT, int maintenanceJ)
        : id(id), type(type), maintenanceT(maintenanceT), maintenanceJ(maintenanceJ) {}
    //getters for attributes
    int getId() { return id; }
    string getType() { return type; }
    int getMaintenanceTime() { return maintenanceT; }
    int getMaintenanceJourneys() { return maintenanceJ; }
    int getCurrentLoad() {return CurrentLoad ;}
    //setter for current load
    void setCurrentLoad(int x){CurrentLoad= x ;}


};