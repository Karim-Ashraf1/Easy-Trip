#pragma once
#include "PriorityQueue.h"
#include "LinkedQueue.h"
#include "Passenger.h"
#include "Bus.h"

class Station {
private:
    int number;
    int timeBetweenStations;
    PriorityQueue<Passenger> WaitingPassengers;
    PriorityQueue<Bus> AvailableBuses;

public:
    Station(int number, int timeBetweenStations)
        : number(number), timeBetweenStations(timeBetweenStations) {}

    int getNumber()  { return number; }
    int getTimeBetweenStations()  { return timeBetweenStations; }

    void addPassenger(const Passenger& passenger) {
        WaitingPassengers.priorityEnqueue(passenger);
    }

    bool removePassenger(Passenger& passenger) {
        return WaitingPassengers.dequeue(passenger);
    }

    void addBus(const Bus& bus) {
        AvailableBuses.priorityEnqueue(bus);
    }

    bool removeBus(Bus& bus) {
        return AvailableBuses.dequeue(bus);
    }

    void checkEndStationAndRemove(getNumber(), Bus busx)
    {
        int i=0;
      while ( i < 45)
       {
            // Check if the end station of the passenger is the current station
            if (busx.PassengersInBus[i].getEndStation() == number) 
            {
                //option to announce arrival
                // std::cout << "Passenger " << passengers[i].getId() << " dequeued at station " << number << std::endl;
                //remove passenger from the array
                passengers[i]=null;
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
                         if (PassengersInBus[i] == nullptr) 
                        {
                                 // Add the passenger to the array at the first available index
                            PassengersInBus[i] = passenger;
                        }    
        
                    }  
                }          
            }
    }
};
