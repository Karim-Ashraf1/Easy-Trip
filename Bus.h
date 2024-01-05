#pragma once
#include "LinkedList.h"
#include <iostream>
#include "Passenger.h"
#include "Time.h"
#include "Station.h"
#include "DoubleLinkedLIst.h"

class Bus
{
private:
    int id;
    
    int Capacity;
    int CurrentLoad;  
    int maintenanceT; // for time
    int maintenanceJ; // for journeys
    int Journy;       // number of journies taken by bus
    int MovingTime;
    int CurrentStation;

    static int tDC; // total passengers transported by this bus
    static int N;   // total delivery trips

    bool Checkup; // to determine whether the bus is currently in maintenance
    char direction; 

    std::string type;

    Time tBT;       // total busy time
    Time TSim;      // total Simulation

    LinkedList<Passenger *> Passengers;

public:

    Bus(int id, std::string type, int CurrentLoad, int MBmaintenanceT, int WBmaintenanceT, int maintenanceJ, char direction)
    {
        id = id;
        type = type;
        CurrentLoad = CurrentLoad;
        MBmaintenanceT = MBmaintenanceT;
        WBmaintenanceT = WBmaintenanceT;
        maintenanceJ = maintenanceJ;
        direction = direction;
    }
    Bus()
    {
        id = 1;
        type = "MBus";
        CurrentLoad = 0;
        maintenanceT = 0;
        maintenanceJ = 0;
        direction = 'F';
        CurrentStation=0;
    }

    // setter for current load
    void setCurrentState(int CurrentStation){this->CurrentStation=CurrentStation;}
    void setJourney(int Journeys) { Journy = Journeys; }
    void setId(int idx) { id = idx; }
    void setType(std::string typex) { type = typex; }
    void setBusMaintenanceTime(int MBMT) { maintenanceT = MBMT; }
    void setMaintenanceJourney(int MJ) { maintenanceJ = MJ; }
    void setCurrentLoad(int CurrentLoadx) { CurrentLoad = CurrentLoadx; }
    void setDirection(char directionx) { direction = directionx; }
    void setPassenger(LinkedList<Passenger *> Passenger) { Passengers = Passenger; }
    void setCapacity(int cap) { Capacity = cap; }
    void setTotalPassenger(static int TotalPassenger) { tDC = TotalPassenger; }
    void setTDC(int x) { tDC = x; }
    void setN(int n) { N = n; }
    void setTBT(Time tbt) { tBT = tbt; }
    void setTSim(Time tsim) { TSim = tsim; }
    void setMovingTime(int timex) { MovingTime = timex; }
    void setChekup(bool IsCheckup) { Checkup = IsCheckup; }


    // getters for attributes
    int getJourney() { return Journy; }
    int getId() { return id; }
    std::string getType() { return type; }
    int getBusMaintenanceTime() { return maintenanceT; }
    bool getIsCheckup() { return Checkup; }
    int getMaintenanceJourneys() { return maintenanceJ; }
    int getCurrentLoad() { return CurrentLoad; }
    char getdirection() { return direction; }
    LinkedList<Passenger *> &GetPassengers() { return Passengers; }
    int getCapacity() { return Capacity; }
    int getN() { return N; }
    static int getTDC() { return tDC; }
    int getCapacity() { return Capacity; }
    Time getTBT() { return tBT; }
    Time getTsim() { return TSim; }
    int getMovingTime() { return MovingTime; }

    int BusUtilization(int tDC, int Bcapacity, int N, Time tBT, Time TSim) { 
        return ((tDC / (Bcapacity)*N)(tBT / TSim)) * 100; };

    int getRemainingCapacity()
    {
        return getCapacity() - getCurrentLoad();
    }

    // void moveBusForward(DoubleLinkedList<Station *> &stationsList, Station &currentStation)
    // {

    //     Node<Station *> *currentNode = stationsList.Find(&currentStation); // Find the current station in the linked list

    //     if (currentNode != nullptr && currentNode->getNext() != nullptr)
    //     {

    //         currentStation.getAvailableBusses().dequeue(*this); // Remove the bus from the current station's

    //         Station *nextStation = currentNode->getNext()->getItem(); // Move the bus to the next station in the linked list
    //         nextStation->getAvailableBusses().enqueue(*this);

    //         std::cout << "Bus " << id << " moved from Station " << currentStation.getNumber() << " to Station " << currentStation.getNumber() + 1 << ".\n";
    //     }
    // }
    // void moveBusBackward(DoubleLinkedList<Station *> &stationsList, Station &currentStation)
    // {

    //     Node<Station *> *currentNode = stationsList.Find(&currentStation); // Find the current station in the linked list

    //     if (currentNode != nullptr && currentNode->getPrev() != nullptr)
    //     {

    //         currentStation.getAvailableBusses().dequeue(*this); // Remove the bus from the current station's

    //         Station *nextStation = currentNode->getPrev()->getItem();
    //         nextStation->getAvailableBusses().enqueue(*this); // Move the bus to the next station in the linked list

    //         std::cout << "Bus " << id << " moved from Station " << currentStation.getNumber() << " to Station " << currentStation.getNumber() - 1 << ".\n";
    //     }
    // }

    void busFromMovingToWaiting(DoubleLinkedList<Station *> &stationsList, Station &currentStation)
    {

        Node<Station *> *waitingStation = stationsList.Find(&currentStation); // Find the current station in the linked list

        if (waitingStation != nullptr)
        {
            
            // currentStation.getAvailableBusses().enqueue(*this); // add the bus to the current station's
        }
    }

    void GetPassOn(LinkedList<Passenger *> &PassengersInBus)
    {
    }




    void checkEndStationAndRemove(Station &station)
    {
        int BoardingTime;
        int loop;
        loop = 60 / BoardingTime;
        for (int i = 0; i < loop; i++)
        {
            Node<Passenger *> *currentNode = Passengers.GetHead();

            // Go over the linked list
            while (currentNode != nullptr)
            {
                // Create a pointer that points to the current passenger
                Passenger *pntr = currentNode->getItem();
                // Create a dummy variable with the same attributes as the passenger
                Passenger psngr = *pntr;
                // Check if the end station of the passenger is the station
                if (psngr.getEndStation() == station.getNumber())
                {
                    // Remove passenger from the linked list
                    Passengers.DeleteNode(pntr);

                    // Update the current load of the bus
                    setCurrentLoad(getCurrentLoad() - 1);

                    // Add the removed passenger to the finish list of the station
                    station.AddToFinishList(*pntr);
                }

                // Move to the next node in the linked list
                currentNode = currentNode->getNext();
            }
        }
    }

    template <typename QueueType>
    void loadPassengersToBus(QueueType &waitingPassengers)
    {
        int maxPassengers = 45;
        int availableSeats = maxPassengers - getCurrentLoad();

        while (availableSeats > 0 && !waitingPassengers.isEmpty())
        {
            Passenger nextPassenger;
            if (waitingPassengers.dequeue(nextPassenger))
            {
                // Add the pointer to the passenger to the bus's linked list
                Passengers.InsertEnd(&nextPassenger);

                setCurrentLoad(getCurrentLoad() + 1);

                // Decrease available seats and continue the loop
                availableSeats--;
            }
        }
    }

    void Bus::boardPassengers(Station &station)
    {
        int BoardingTime;
        int loop;
        loop = 60 / BoardingTime;
        for (int i = 0; i < loop; i++)
        {
            // Check the direction first
            if (getdirection() == 'F')
            {
                // Forward direction
                if (getType() == "NP")
                {
                    // Normal bus
                    loadPassengersToBus(station.getNormalWaitingPassengersForward());
                }
                else if (getType() == "WP")
                {
                    // Wheelchair bus
                    loadPassengersToBus(station.getWheelchairWaitingPassengersForwards());
                }
            }
            else if (getdirection() == 'B')
            {
                // Backward direction
                if (getType() == "NP")
                {
                    // Normal bus
                    loadPassengersToBus(station.getNormalWaitingPassengersBackward());
                }
                else if (getType() == "WP")
                {
                    // Wheelchair bus
                    loadPassengersToBus(station.getWheelchairWaitingPassengersBackwards());
                }
            }
        }
    }
};