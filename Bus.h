#pragma once
#include "LinkedList.h"
#include <iostream>
#include "Passenger.h"
#include "Time.h"
#include "Station.h"
#include "DoubleLinkedLIst.h"
#include "Functions.h"
int id= 0;
class Bus
{
private:
    int ID=0;
    int FirstOnTime, LastOffTime;
    int BusyTime;
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

    int tBT;  // total busy time
    int TSim; // total Simulation

    LinkedList<Passenger *> Passengers;
    PriorityQueue<Passenger *> MovingPassengersList;

public:
    Bus(int ID, std::string type, int CurrentLoad, int MBmaintenanceT, int WBmaintenanceT, int maintenanceJ, char direction)
    {
        ID = ID;
        type = type;
        CurrentLoad = CurrentLoad;
        MBmaintenanceT = MBmaintenanceT;
        WBmaintenanceT = WBmaintenanceT;
        maintenanceJ = maintenanceJ;
        direction = direction;
    }
    Bus()
    {
        ID = 1;
        type = "MBus";
        CurrentLoad = 0;
        maintenanceT = 0;
        maintenanceJ = 0;
        direction = 'F';
        CurrentStation = 0;
    }
    Bus(string type,int Capacity,int maintenanceJ)
        :type(type),Capacity(Capacity),maintenanceJ(maintenanceJ){
            Checkup=false;
            maintenanceT=MovingTime=Journy=0;
            CurrentStation=0;
            ID=id;
            id++;
        }

    // setter for current load
    void setCurrentStation(int CurrentStation) { this->CurrentStation = CurrentStation; }
    void setJourney(int Journeys) { Journy = Journeys; }
    void setId(int idx) { ID = idx; }
    void setType(std::string typex) { type = typex; }
    void setBusMaintenanceTime(int MBMT) { maintenanceT = MBMT; }
    void setMaintenanceJourney(int MJ) { maintenanceJ = MJ; }
    void setCurrentLoad(int CurrentLoadx) { CurrentLoad = CurrentLoadx; }
    void setDirection(char directionx) { direction = directionx; }
    void setPassenger(LinkedList<Passenger *> Passenger) { Passengers = Passenger; }
    void setCapacity(int cap) { Capacity = cap; }
    void setTotalPassenger(int TotalPassenger) { tDC = TotalPassenger; }
    void setTDC(int x) { tDC = x; }
    void setN(int n) { N = n; }
    void setTBT(int tbt) { tBT = tbt; }
    void setTSim(int tsim) { TSim = tsim; }
    void setMovingTime(int timex) { MovingTime = timex; }
    void setChekup(bool IsCheckup) { Checkup = IsCheckup; }

    // getters for attributes
    int getCurrentStation() { return CurrentStation; }
    int getJourney() { return Journy; }
    int getId() { return ID; }
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
    int getTBT() { return tBT; }
    int getTsim() { return TSim; }
    int getMovingTime() { return MovingTime; }
    int getBusyTime() { return BusyTime; }

    int BusBusyTime()
    {
        BusyTime = LastOffTime - FirstOnTime;
    }
    int BusUtilization()
    {
        Time time;
        time.convertTotalMinutesToTime(tBT / TSim);
        int minutes = time.calculateTotalMinutes();
        int x = (tDC * N / (Capacity));
        return (x * minutes * 100);
    };

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

    //void busFromMovingToWaiting(DoubleLinkedList<Station *> &stationsList, Station &currentStation)
 //    {
 //
  //       Node<Station *> *waitingStation = stationsList.Find(&currentStation); // Find the current station in the linked list
 //
 //        if (waitingStation != nullptr)
 //        {
  //
 //             currentStation.getAvailableBusses().enqueue(*this); // add the bus to the current station's
 //        }
 //    }

    void JournyIncrement()
    {
        Journy++;
        if (Journy == maintenanceJ)
        {
            Checkup = true;
            Journy = 0;
        }
    }

    bool PassengerOff()
    {
        if (MovingPassengersList.isEmpty())
            return false;
        int nextStation = (direction == 'F') ? CurrentStation + 1 : CurrentStation - 1;
        return MovingPassengersList.peek()->getEndStation() == nextStation;
    }

    void checkEndStationAndRemove(Station station, string Filename,int currenttime, LinkedQueue<Passenger *> FinishList)
    {
        int BoardingTime = GetBoardingTime(Filename);
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

                    //set the passenger get off time as current time
                    psngr.setOFFTime(currenttime);

                    // Add the removed passenger to the finish list of the station
                    FinishList.enqueue(pntr);
                    if(psngr.getOFFTime()>LastOffTime){
                        LastOffTime=psngr.getOFFTime();
                        BusyTime=LastOffTime-FirstOnTime;
                    }
                
                }

                // Move to the next node in the linked list
                currentNode = currentNode->getNext();
            }
        }
    }
    void loadChairPassengersToBus(LinkedQueue <Passenger*>& waitingPassengers, int currenttime)
    {
        int maxPassengers = Capacity;
        int availableSeats = maxPassengers - getCurrentLoad();

        while (availableSeats > 0 && !waitingPassengers.isEmpty())
        {
            Passenger nextPassenger;


            nextPassenger = *waitingPassengers.dequeue();
            // Add the pointer to the passenger to the bus's linked list
            Passengers.InsertEnd(&nextPassenger);
            //set the passenger get on time as current time
            nextPassenger.setOnTime(currenttime);
            setCurrentLoad(getCurrentLoad() + 1);

            // Decrease available seats and continue the loop
            availableSeats--;
            if (nextPassenger.getOnTime() < FirstOnTime) {
                FirstOnTime = nextPassenger.getOnTime();
            }

        }
    }
    
    void loadNormalPassengersToBus(LinkedList <Passenger*> &waitingPassengers, int currenttime)
    {
        int maxPassengers = Capacity;
        int availableSeats = maxPassengers - getCurrentLoad();

        while (availableSeats > 0 && !waitingPassengers.IsEmpty())
        {
            Passenger nextPassenger;
            
            
                nextPassenger = *waitingPassengers.GetHead()->getItem();
                // Add the pointer to the passenger to the bus's linked list
                Passengers.InsertEnd(&nextPassenger);
                //set the passenger get on time as current time
                nextPassenger.setOnTime(currenttime);
                setCurrentLoad(getCurrentLoad() + 1);

                // Decrease available seats and continue the loop
                availableSeats--;
                if(nextPassenger.getOnTime()<FirstOnTime){
                    FirstOnTime = nextPassenger.getOnTime();
                }
            
        }
    }
    void loadSpecialPassengersToBus(PriorityQueue <Passenger*>& waitingPassengers, int currenttime)
    {
        int maxPassengers = Capacity;
        int availableSeats = maxPassengers - getCurrentLoad();

        while (availableSeats > 0 && !waitingPassengers.isEmpty())
        {
            Passenger nextPassenger;


            nextPassenger = *waitingPassengers.dequeue();
            // Add the pointer to the passenger to the bus's linked list
            Passengers.InsertEnd(&nextPassenger);
            //set the passenger get on time as current time
            nextPassenger.setOnTime(currenttime);
            setCurrentLoad(getCurrentLoad() + 1);

            // Decrease available seats and continue the loop
            availableSeats--;
            if (nextPassenger.getOnTime() < FirstOnTime) {
                FirstOnTime = nextPassenger.getOnTime();
            }

        }
    }

    void boardPassengers(Station &station, string Filename, int currenttime)
    {
        int BoardingTime = GetBoardingTime(Filename);
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
                    PriorityQueue<Passenger*> queue= station.getSpecialWaitingPassFwd();
                    // Normal bus
                    loadSpecialPassengersToBus(queue, currenttime);
                    LinkedList <Passenger*> List = station.getNormalWaitingPassengersForward();
                    loadNormalPassengersToBus(List, currenttime);
                }
                else if (getType() == "WP")
                {
                    // Wheelchair bus
                    LinkedQueue <Passenger*> Lqueue = station.getWChairWaitingPassFwd();
                    loadChairPassengersToBus(Lqueue, currenttime);
                }
            }
            else if (getdirection() == 'B')
            {
                // Backward direction
                if (getType() == "NP")
                {
                    // Normal bus
                    PriorityQueue<Passenger*> queue = station.getSpecialWaitingPassBwd();
                    loadSpecialPassengersToBus(queue, currenttime);
                    LinkedList <Passenger*> List = station.getNormalWaitingPassengersBackward();
                    loadNormalPassengersToBus(List, currenttime);
                }
                else if (getType() == "WP")
                {
                    // Wheelchair bus
                    LinkedQueue <Passenger*> Lqueue = station.getWChairWaitingPassBwd();
                    loadChairPassengersToBus(Lqueue, currenttime);
                }
            }
        }
    }
};