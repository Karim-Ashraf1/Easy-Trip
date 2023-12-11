#pragma once
#include "PriorityQueue.h"
#include "LinkedQueue.h"
#include "Passenger.h"
#include "Bus.h"

class Station {
private:
    int number;
    int timeBetweenStations;
    PriorityQueue<Passenger> NormalWaitingPassengers;
    LinkedQueue<Passenger> WheelchairWaitingPassengers;
    LinkedQueue<Bus> AvailableBuses;

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
                            bus.setTotalPassengers((bus.getTotalPassengers()+1));
                        }    
        
                    }  
                }          
            }
    }
};
