#pragma once
#include "PriorityQueue.h"
#include "LinkedQueue.h"
#include "Passenger.h"
#include "Bus.h"
#include "LinkedList.h"

class Station {
private:
    int number;
    int timeBetweenStations;
    PriorityQueue<Passenger> NormalWaitingPassengersForward;
    PriorityQueue<Passenger> NormalWaitingPassengersBackward;
    LinkedQueue<Passenger> WheelchairWaitingPassengersForwards;
    LinkedQueue<Passenger> WheelchairWaitingPassengersBackwards;
    LinkedQueue<Bus*> AvailableBuses;
    LinkedList<Passenger*> FinishList;
    LinkedQueue<Bus*> NormalPassengersMovingBusesForward;
    LinkedQueue<Bus*> NormalPassengersMovingBusesBackward;
    LinkedQueue<Bus*> WheelchairPassengersMovingBusesForward;
    LinkedQueue<Bus*> WheelchairPassengersMovingBusesBackward;
    LinkedQueue<Bus*> movingBusses;

public:
    void setNumber(int newNumber) {
        number = newNumber;
    }

    
    int getNumber() const {
        return number;
    }

    
    void setTimeBetweenStations(int newTime) {
        timeBetweenStations = newTime;
    }

    
    int getTimeBetweenStations() const {
        return timeBetweenStations;
    }

    
    void setNormalWaitingPassengersForward(const PriorityQueue<Passenger>& passengers) {
        NormalWaitingPassengersForward = passengers;
    }
    void setNormalWaitingPassengersBackrward(const PriorityQueue<Passenger>& passengers) {
        NormalWaitingPassengersBackward = passengers;
    }
    void setWheelchairWaitingPassengersForwards(const LinkedQueue<Passenger>& passengers) {
        WheelchairWaitingPassengersForwards = passengers;
    }
    void setWheelchairWaitingPassengersBackwards(const LinkedQueue<Passenger>& passengers) {
        WheelchairWaitingPassengersBackwards = passengers;
    }
     void setAvailableBusses(const LinkedQueue<Bus*>& busses) {
        AvailableBuses = busses;
    }
    
    PriorityQueue<Passenger>& getNormalWaitingPassengersForward() {
        return NormalWaitingPassengersForward;
    }
    PriorityQueue<Passenger>& getNormalWaitingPassengersBackward() {
        return NormalWaitingPassengersBackward;
    }
    LinkedQueue<Passenger>& getWheelchairWaitingPassengersForwards() {
        return WheelchairWaitingPassengersForwards;
    }
      LinkedQueue<Passenger>& getWheelchairWaitingPassengersBackwards() {
        return WheelchairWaitingPassengersBackwards;
    }
      LinkedQueue<Bus*>& getAvailableBusses() {
        return AvailableBuses;
    }
      LinkedList<Passenger*>& getFinishlist() {
        return FinishList;
    }
    Station(){
        number=0;
        timeBetweenStations=0;

    }
    Station(int number, int timeBetweenStations)
        : number(number), timeBetweenStations(timeBetweenStations) {}



    

    void AddToFinishList(Passenger psngr){
        Passenger* pntr;
        pntr= &psngr;
        FinishList.InsertEnd(pntr);
    }
    void printFinishListAttributes() const {
        std::cout << "Passengers in FinishList at Station " << number << ":\n";

        Node<Passenger*>* current = FinishList.Head; 

        while (current != nullptr) {
            Passenger* passenger = current->getItem();
 
            // Print attributes of the passenger
            std::cout << "ID: " << passenger->getId() << "\n";
            std::cout << "Start Station: " << passenger->getStartStation() << "\n";
            std::cout << "End Station: " << passenger->getEndStation() << "\n";
            std::cout << "On Time: " ;
            passenger->getOnTime();
            std::cout << "OFF Time: " ;
            passenger->getOFFTime();
            std::cout << "Type: " << passenger->getType() << "\n";
            if (passenger->getType()=="SP"){
                std::cout << "Subtype: " << passenger->getsubtype() << "\n";
            }

            // Move to the next node in the linked list
            current = current->getNext();
        }
    }
  
    void moveBusFromMovingToWaiting() {

    }
    
    void busFromMovingToWaiting(DoubleLinkedList<Station *> &stationsList, Station &currentStation)
    {

        Node<Station *> *waitingStation = stationsList.Find(&currentStation); // Find the current station in the linked list

        if (waitingStation != nullptr)
        {
            // currentStation.getAvailableBusses().enqueue(*this); // add the bus to the current station's
        }
    }

    void moveBusFromWatingToMoving() {
        Bus* b;
        if (!AvailableBuses.isEmpty()) {
            AvailableBuses.peek(b);
            AvailableBuses.dequeue(b);
            b->boardPassengers(*this);
            movingBusses.enqueue(b);
        }
        else { cout<<"No Busses is waiting"; }
    }


    void addBusses(Bus *bus) {
        if (bus->getdirection() == 'F' && bus->getType()=="MBus")
        {
            NormalPassengersMovingBusesForward.enqueue(bus);
        }
        else if (bus->getdirection() == 'F' && bus->getType()=="WBus")
        {
           WheelchairPassengersMovingBusesForward.enqueue(bus);
        }
        if (bus->getdirection() == 'B' && bus->getType()=="MBus")
        {
            NormalPassengersMovingBusesBackward.enqueue(bus);
        }
        if (bus->getdirection() == 'B' && bus->getType()=="WBus")
        {
           WheelchairPassengersMovingBusesBackward.enqueue(bus);
        }
    }
    // checks passenger type and add it to the relevant qeue
    void addPassenger (Passenger *psngr) {
        string PassengerType=psngr->getType();

        if (PassengerType=="NP"){
            if (psngr->getStartStation() < psngr->getEndStation()){
                waitingFNP.InsertEnd(psngr);
            }
            else{
                waitingBNP.InsertEnd(psngr);
            }
        }
        else if (PassengerType=="SP"){
            if (psngr->getStartStation() < psngr->getEndStation()){
                waitingFSP.priorityEnqueue(psngr);
            }
            else{
                waitingBSP.priorityEnqueue(psngr);
            }
        }
        if (PassengerType=="WP"){
            if (psngr->getStartStation() < psngr->getEndStation()){
                waitingFWP.enqueue(psngr);
            }
            else{
                waitingBWP.enqueue(psngr);
            }
        }
    }
};
