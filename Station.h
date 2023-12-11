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
    Station(int number, int timeBetweenStations)
        : number(number), timeBetweenStations(timeBetweenStations) {}

    int getNumber()  { return number; }

    int getTimeBetweenStations()  { return timeBetweenStations; }

    void addBus(const Bus& bus) {
        AvailableBuses.enqueue(bus);
    }

    bool removeBus(Bus& bus) {
        return AvailableBuses.dequeue(bus);
    }

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
            passenger->getOnTime().toString();
            std::cout << "OFF Time: " ;
            passenger->getOFFTime().toString();
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
};
