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
    LinkedQueue<Bus> AvailableBuses;
    LinkedList<Passenger*> FinishList;


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
     void setAvailableBusses(const LinkedQueue<Bus>& busses) {
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
      LinkedQueue<Bus>& getAvailableBusses() {
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
  

    void checkEndStationAndRemove(Station stationx, Bus busx)
    {
        int i=0;
      while ( i < 45)
       {    
            //create a pointer that points to the same passenger
            Passenger* pntr=busx.PassengersInBus[i];
            //create another passenger with the same attributes
            Passenger psngr = *pntr;
            // Check if the end station of the passenger is the current station
            if (psngr.getEndStation() == stationx.getNumber()) 
            {
                //remove passenger from the array
                busx.PassengersInBus[i]=nullptr;
                busx.setCurrentLoad((busx.getCurrentLoad()-1));
           
            }
            i++;
        }
    }    
    void loadPassengersToBus(PriorityQueue<Passenger>& waitingPassengers, Bus& bus)
    {
        int maxPassengers = 45;
        int availableSeats = maxPassengers - bus.getCurrentLoad();

             while (availableSeats > 0 && !waitingPassengers.isEmpty())
            {
                 Passenger nextPassenger;
                 if (waitingPassengers.dequeue(nextPassenger))
                {
                     for (int i = 0; i < 45; ++i) 
                    {
                        Passenger* pntr=bus.PassengersInBus[i];
                        Passenger psngr = *pntr;    
                         if (psngr.getId()==0) 
                        {
                            Passenger* pntr2 = &nextPassenger;
                            // Add the pointer to the passenger to the array at the first available index
                            bus.PassengersInBus[i] = pntr2 ;
                            bus.setCurrentLoad((bus.getCurrentLoad()+1));
                            bus.setTDC((bus.getTDC()+1));
                        }    
        
                    }  
                }          
            }
    }

    void moveBusFromWatingToMoving() {
        while (!AvailableBuses.isEmpty()) {
            Bus currentBus;
            if (AvailableBuses.dequeue(currentBus)) {
                // Load passengers to bus
                loadPassengersToBus(NormalWaitingPassengersForward, currentBus);
                loadPassengersToBus(NormalWaitingPassengersBackward, currentBus);
                // loadPassengersToBus(WheelchairWaitingPassengersForwards, currentBus);
                // loadPassengersToBus(WheelchairWaitingPassengersBackwards, currentBus);

                currentBus.moveBus();

                // Check if any passengers have reached their destination
                checkEndStationAndRemove(*this, currentBus);

                // Add the bus back to the available buses queue if it still has space
                if (currentBus.getCurrentLoad() < currentBus.getCapacity()) {
                    AvailableBuses.enqueue(currentBus);
                }
            }
    }
    }
};
