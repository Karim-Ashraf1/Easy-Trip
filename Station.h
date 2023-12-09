#include "PriorityQueue.h"
#include "LinkedQueue.h"
#include "Passenger.h"
#include "Events.h"
#include "Bus.h"

class Station {
private:
    int number;
    int timeBetweenStations;
    PriorityQueue<Passenger> WaitingPassengers;
    PriorityQueue<Events> Events;
    LinkedQueue<Bus> AvailableBuses;

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

    void addEvent(const Event& event) {
        Events.priorityEnqueue(event);
    }

    bool removeEvent(Event& event) {
        return Events.dequeue(event);
    }

    void addBus(const Bus& bus) {
        AvailableBuses.priorityEnqueue(bus);
    }

    bool removeBus(Bus& bus) {
        return AvailableBuses.dequeue(bus);
    }

    void checkEndStationAndRemove(getNumber, Passenger passengers[45]) {
    for (int i = 0; i < 45; ++i) {
        // Check if the end station of the passenger is the current station
        if (passengers[i].getEndStation() == currentStation) {
            //option to announce arrival
            // std::cout << "Passenger " << passengers[i].getId() << " dequeued at station " << number << std::endl;
            //remove passenger from the array
            passengers[i]=null;

           
        }
    }
}

 
};