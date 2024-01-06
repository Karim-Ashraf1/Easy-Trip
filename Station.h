#pragma once
#include "PriorityQueue.h"
#include "LinkedQueue.h"
#include "Passenger.h"
#include "Bus.h"
#include "LinkedList.h"

class Station
{
private:
    int number;
    int timeBetweenStations;
    LinkedList<Passenger*> NormalWaitingPassFwd;
    /* not the best data structure was needed to implement promotePassenger function */
    LinkedList<Passenger*> NormalWaitingPassBwd;
    PriorityQueue<Passenger*> SpecialWaitingPassFwd;
    PriorityQueue<Passenger*> SpecialWaitingPassBwd;
    LinkedQueue<Passenger*> WChairWaitingPassFwd;
    LinkedQueue<Passenger*> WChairWaitingPassBwd;
    LinkedQueue<Bus *> AvailableBuses;
    LinkedList<Passenger *> FinishList;
    LinkedQueue<Bus *> NormalPassengersMovingBusesForward;
    LinkedQueue<Bus *> NormalPassengersMovingBusesBackward;
    LinkedQueue<Bus *> WheelchairPassengersMovingBusesForward;
    LinkedQueue<Bus *> WheelchairPassengersMovingBusesBackward;
    LinkedQueue<Bus *> movingBusses;

public:
    void setNumber(int newNumber)
    {
        number = newNumber;
    }

    int getNumber() const
    {
        return number;
    }

    void setTimeBetweenStations(int newTime)
    {
        timeBetweenStations = newTime;
    }

    int getTimeBetweenStations() const
    {
        return timeBetweenStations;
    }
    Station()
    {
        number = 0;
        timeBetweenStations = 0;
    }
    Station(int number, int timeBetweenStations)
        : number(number), timeBetweenStations(timeBetweenStations) {}

    void AddToFinishList(Passenger psngr)
    {
        Passenger *pntr;
        pntr = &psngr;
        FinishList.InsertEnd(pntr);
    }
    template <typename T>
    void printFinishListAttributes() const
    {
        std::cout << "Passengers in FinishList at Station " << number << ":\n";

        Node<T> *current = FinishList.GetHead();
        ;

        while (current != nullptr)
        {
            Passenger *passenger = current->getItem();

            // Print attributes of the passenger
            std::cout << "ID: " << passenger->getId() << "\n";
            std::cout << "Start Station: " << passenger->getStartStation() << "\n";
            std::cout << "End Station: " << passenger->getEndStation() << "\n";
            std::cout << "On Time: ";
            passenger->getOnTime();
            std::cout << "OFF Time: ";
            passenger->getOFFTime();
            std::cout << "Type: " << passenger->getType() << "\n";
            if (passenger->getType() == "SP")
            {
                std::cout << "Subtype: " << passenger->getsubtype() << "\n";
            }

            // Move to the next node in the linked list
            current = current->getNext();
        }
    }

    void busFromMovingToWaiting(Station *StationsArray, Bus bus, string Filename)
    {
        int y;
        int *movingtime = ConvertToInt((GetFileLine(Filename, 1, 'O')));
        y = *(movingtime + 1);
        if (bus.getMovingTime() == y)
        {
            bus.setCurrentStation((bus.getCurrentStation() + 1));
            Station station = StationsArray[bus.getCurrentStation()];
            bus.checkEndStationAndRemove(station, Filename);
        }
    }

    void addBusses(Bus *bus)
    {
        if (bus->getdirection() == 'F' && bus->getType() == "MBus")
        {
            NormalPassengersMovingBusesForward.enqueue(bus);
        }
        else if (bus->getdirection() == 'F' && bus->getType() == "WBus")
        {
            WheelchairPassengersMovingBusesForward.enqueue(bus);
        }
        if (bus->getdirection() == 'B' && bus->getType() == "MBus")
        {
            NormalPassengersMovingBusesBackward.enqueue(bus);
        }
        if (bus->getdirection() == 'B' && bus->getType() == "WBus")
        {
            WheelchairPassengersMovingBusesBackward.enqueue(bus);
        }
    }
    // checks passenger type and add it to the relevant qeue
    void addPassenger(Passenger *psngr)
    {
        string PassengerType = psngr->getType();

        if (PassengerType == "NP")
        {
            if (psngr->getStartStation() < psngr->getEndStation())
            {
                NormalWaitingPassFwd.InsertEnd(psngr);
            }
            else
            {
                NormalWaitingPassBwd.InsertEnd(psngr);
            }
        }
        else if (PassengerType == "SP")
        {
            if (psngr->getStartStation() < psngr->getEndStation())
            {
                SpecialWaitingPassFwd.priorityEnqueue(psngr);
            }
            else
            {
                SpecialWaitingPassBwd.priorityEnqueue(psngr);
            }
        }
        if (PassengerType == "WP")
        {
            if (psngr->getStartStation() < psngr->getEndStation())
            {
                WChairWaitingPassFwd.enqueue(psngr);
            }
            else
            {
                WChairWaitingPassBwd.enqueue(psngr);
            }
        }
    }

    int promotePassenger(int time, int maxW)
    {
        int promotedPassCount = 0;
        LinkedQueue<Passenger *> promotePassengers;
        Node<Passenger*> *pass = NormalWaitingPassFwd.GetHead();
        Node<Passenger *> *passenger = NormalWaitingPassBwd.GetHead();
        while (pass != nullptr)
        {
            int waitingTime = time - pass->getItem()->getArrival();
            if (waitingTime > maxW)
            {
                promotedPassCount++;
                promotePassengers.enqueue(pass);
            }
        }
        while (!promotePassengers.isEmpty())
        {
            Passenger *passenger = promotePassengers.dequeue();
            NormalWaitingPassFwd.DeleteNode(passenger);
            Passenger psngr = *passenger;
            SpecialWaitingPassFwd.priorityEnqueue(psngr);
        }
        while (passenger != nullptr)
        {
            int waitingTime = time - passenger->getItem()->getArrival();
            if (waitingTime > maxW)
            {
                promotedPassCount++;
                promotePassengers.enqueue(passenger);
            }
        }
        while (!promotePassengers.isEmpty())
        {
            Passenger *passenger = promotePassengers.dequeue();
            NormalWaitingPassBwd.DeleteNode(passenger);
            Passenger psngr = *passenger;
            SpecialWaitingPassBwd.priorityEnqueue(psngr);
        }

        return promotedPassCount;
    }

    // checks if there are busses Nedded in the station
    bool BusNeeded(Bus *bus)
    {
        if (bus->getType() == "MBus")
        {
            if (bus->getdirection() == 'F')
                return !NormalWaitingPassFwd.IsEmpty() || !SpecialWaitingPassFwd.isEmpty(); // if there waitng Normal FWD passenger returns true
            else
            {
                return !NormalWaitingPassBwd.IsEmpty() || !SpecialWaitingPassBwd.isEmpty(); // if there waitng Normal BWD passenger returns true
            }
        }
        else
        {
            if (bus->getdirection() == 'F')
                return !WChairWaitingPassFwd.isEmpty(); // if there waitng WheelChair FWD passenger returns true
            else
            {
                return !WChairWaitingPassBwd.isEmpty(); // if there waitng WheelChair BWD passenger returns true
            }
        }
    }
};