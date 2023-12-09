#pragma once
#include <iostream>
#include <LinkedQueue.h>
#include "Passenger.h"
#include "Time.h"
class Bus {
private:
    int id;
    std::string type;
    static const int Bcapacity = 45;
    int CurrentLoad; //
    int maintenanceT; // for time
    int maintenanceJ; // for journeys
    static int tDC = 0; // total passengers transported by this bus
    static int N = 0; // total delivery trips
    Time tBT; // total busy time
    Time TSim; // total Simulation
public:
    Passenger PassengersInBus[Bcapacity];
    Bus(int id, std::string type, int maintenanceT, int maintenanceJ)
        : id(id), type(type), maintenanceT(maintenanceT), maintenanceJ(maintenanceJ) {}
    //getters for attributes
    int getId() { return id; }
    std::string getType() { return type; }
    int getMaintenanceTime() { return maintenanceT; }
    int getMaintenanceJourneys() { return maintenanceJ; }
    int getCurrentLoad() {return CurrentLoad ;}
    int getN(int N) { return N++ ;}
    //setter for current load
    void setCurrentLoad(int x){CurrentLoad= x ;}
    int BusUtilization(int tDC, int Bcapacity, int N, int tBT, int TSim){return (tDC/(Bcapacity *N) * (tBT/TSim))*100 << "%";}


};