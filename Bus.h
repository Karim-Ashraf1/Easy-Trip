#pragma once
#include "LinkedList.h"
#include <iostream>
#include "Passenger.h"
#include "Time.h"
#include "Station.h"
#include "DoubleLinkedLIst.h"

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
        id = id; type = type; CurrentLoad = CurrentLoad;
        maintenanceT = maintenanceT; maintenanceJ = maintenanceJ; direction = direction;
    }
    Bus(){
        id = 1; type = "MBus";
        CurrentLoad = 0;
        maintenanceT = 0;
        maintenanceJ = 0;
        direction = 'F';
    }

    //setter for current load
    void setId(int idx) {id = idx;}
    void setType(std::string typex) {type = typex;}
    void setCurrentLoad(int CurrentLoadx){CurrentLoad = CurrentLoadx ;}
    void setdirection(char directionx){direction = directionx ;}
    void setTotalPassenger(static int TotalPassenger) {tDC = TotalPassenger;}
    void setTDC(int x){tDC = x;}
    void setN(int n){N=n;}
    void setTBT(Time tbt){tBT=tbt;}
    void setTSim(Time tsim){TSim=tsim;}

    //getters for attributes
    int getId() { return id;}
    std::string getType() { return type; }
    int getMaintenanceTime() { return maintenanceT; }
    int getMaintenanceJourneys() { return maintenanceJ; }
    int getCurrentLoad() {return CurrentLoad ;}
    int getN() { return N;}
    char getdirection() { return direction ;}
    static int getTDC() {return tDC;}
    int getCapacity(){return Bcapacity;}
    Time getTBT(){return tBT;}
    Time getTsim(){return TSim;}

    int BusUtilization(int tDC, int Bcapacity, int N, Time tBT, Time TSim){return (tDC/(Bcapacity *N) * (tBT/TSim))*100;};

    void moveBusForward(DoubleLinkedList<Station*>& stationsList, Station& currentStation) {
        // Find the current station in the linked list
        Node<Station*>* currentNode = stationsList.Find(&currentStation);

        if (currentNode != nullptr && currentNode->getNext() != nullptr) {
            // Remove the bus from the current station's
            currentStation.getAvailableBusses().dequeue(*this);
            // Move the bus to the next station in the linked list
            Station* nextStation = currentNode->getNext()->getItem();
            nextStation->getAvailableBusses().enqueue(*this);
            cout << "Bus " << id << " moved from Station " << currentStation.getNumber() << " to Station " << currentStation.getNumber() + 1<< ".\n";
        }
    }
    void moveBusBackward(DoubleLinkedList<Station*>& stationsList, Station& currentStation) {
        // Find the current station in the linked list
        Node<Station*>* currentNode = stationsList.Find(&currentStation);

        if (currentNode != nullptr && currentNode->getPrev() != nullptr) {
            // Remove the bus from the current station's
            currentStation.getAvailableBusses().dequeue(*this);
            // Move the bus to the next station in the linked list
            Station* nextStation = currentNode->getPrev()->getItem();
            nextStation->getAvailableBusses().enqueue(*this);
            cout << "Bus " << id << " moved from Station " << currentStation.getNumber() << " to Station " << currentStation.getNumber() - 1<< ".\n";
        }
    }

};