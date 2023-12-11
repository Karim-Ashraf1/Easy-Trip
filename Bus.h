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
    static int tDC; // total passengers transported by this bus
    static int N; // total delivery trips
    Time tBT; // total busy time
    Time TSim; // total Simulation
    char direction;
public:
    Passenger* PassengersInBus[Bcapacity];
    Bus(int id, std::string type, int CurrentLoad, int maintenanceT, int maintenanceJ, char direction){
        id = 1; type = "MBus"; CurrentLoad = 0;
        maintenanceT = 0; maintenanceJ = 0; direction = "F";
    }

    //setter for current load
    void setCurrentLoad(int x){CurrentLoad = x ;}
    void setdirection(char x){direction = x ;}
    void setTotalPassenger(static int TotalPassenger) {tDC = TotalPassenger;}
    void setTDC(){tDC = 0;}
    //getters for attributes
    int getId() { return id;}
    std::string getType() { return type; }
    int getMaintenanceTime() { return maintenanceT; }
    int getMaintenanceJourneys() { return maintenanceJ; }
    int getCurrentLoad() {return CurrentLoad ;}
    int getN() { return N;}
    char getdirection() { return direction ;}
    static int getTotalPassenger() {return tDC;}

    int BusUtilization(int tDC, int Bcapacity, int N, int tBT, int TSim){return (tDC/(Bcapacity *N) * (tBT/TSim))*100;}

};