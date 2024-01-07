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
    LinkedList<Passenger *> NormalWaitingPassFwd;
    /* not the best data structure was needed to implement promotePassenger function */
    LinkedList<Passenger *> NormalWaitingPassBwd;
    PriorityQueue<Passenger *> SpecialWaitingPassFwd;
    PriorityQueue<Passenger *> SpecialWaitingPassBwd;
    LinkedQueue<Passenger *> WChairWaitingPassFwd;
    LinkedQueue<Passenger *> WChairWaitingPassBwd;
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
    LinkedQueue<Bus *> getNormalPassengersMovingBusesForward()
    {
        return NormalPassengersMovingBusesForward;
    }
    LinkedQueue<Bus *> getNormalPassengersMovingBusesBackward()
    {
        return NormalPassengersMovingBusesBackward;
    }
    LinkedQueue<Bus *> getWheelchairPassengersMovingBusesForward()
    {
        return WheelchairPassengersMovingBusesForward;
    }
    LinkedQueue<Bus *> getWheelchairPassengersMovingBusesBackward()
    {
        return WheelchairPassengersMovingBusesBackward;
    }
    LinkedList<Passenger *> getNormalWaitingPassengersForward()
    {
        return NormalWaitingPassFwd;
    }
    LinkedList<Passenger *> getNormalWaitingPassengersBackward()
    {
        return NormalWaitingPassBwd;
    }
    PriorityQueue<Passenger *> getSpecialWaitingPassFwd()
    {
        return SpecialWaitingPassFwd;
    }
    PriorityQueue<Passenger *> getSpecialWaitingPassBwd()
    {
        return SpecialWaitingPassBwd;
    }
    LinkedQueue<Passenger *> getWChairWaitingPassFwd()
    {
        return WChairWaitingPassFwd;
    }
    LinkedQueue<Passenger *> getWChairWaitingPassBwd()
    {
        return WChairWaitingPassBwd;
    }
    Station()
    {
        number = 0;
        timeBetweenStations = 0;
    }
    Station(int number, int timeBetweenStations)
        : number(number), timeBetweenStations(timeBetweenStations) {}

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

    void PassengerLeave(int ID)
    {
        Node<Passenger *> *rakeb = NormalWaitingPassFwd.GetHead();
        Node<Passenger *> *passenger = NormalWaitingPassBwd.GetHead();
        while (rakeb != nullptr)
        {
            if (rakeb->getItem()->getId() == ID)
            {
                NormalWaitingPassFwd.DeleteNode(rakeb->getItem());
                return;
            }
        }
        while (passenger != nullptr)
        {
            if (passenger->getItem()->getId() == ID)
            {
                NormalWaitingPassBwd.DeleteNode(passenger->getItem());
                return;
            }
        }
    }

    int promotePassenger(int time, int maxW)
    {
        int promotedPassCount = 0;
        LinkedQueue<Passenger *> promotePassengersFwd;
        LinkedQueue<Passenger *> promotePassengersBwd;
        Node<Passenger *> *passFwd = NormalWaitingPassFwd.GetHead();
        Node<Passenger *> *passBwd = NormalWaitingPassBwd.GetHead();
        while (passFwd != nullptr)
        {
            int waitingTime = time - passFwd->getItem()->getArrival();
            if (waitingTime > maxW)
            {
                promotedPassCount++;
                promotePassengersFwd.enqueue(passFwd->getItem());
                passFwd = passFwd->getNext();
            }
            else
                passFwd = passFwd->getNext();
        }
        while (!promotePassengersFwd.isEmpty())
        {
            Passenger *passenger = promotePassengersFwd.dequeue();
            NormalWaitingPassFwd.DeleteNode(passenger);
            SpecialWaitingPassFwd.priorityEnqueue(passenger);
        }
        while (passBwd != nullptr)
        {
            int waitingTime = time - passBwd->getItem()->getArrival();
            if (waitingTime > maxW)
            {
                promotedPassCount++;
                promotePassengersBwd.enqueue(passBwd->getItem());
                passBwd = passBwd->getNext();
            }
            else
                passBwd = passBwd->getNext();
        }
        while (!promotePassengersBwd.isEmpty())
        {
            Passenger *passenger = promotePassengersBwd.dequeue();
            NormalWaitingPassBwd.DeleteNode(passenger);
            SpecialWaitingPassBwd.priorityEnqueue(passenger);
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
    Bus *removeNPFwdBus()
    {
        if (!NormalPassengersMovingBusesForward.isEmpty() && (!NormalPassengersMovingBusesForward.peek()->checkAddPassenger() || !BusNeeded(NormalPassengersMovingBusesForward.peek())))
        {
            return NormalPassengersMovingBusesForward.dequeue();
        }
        else
            return nullptr;
    }
    Bus *removeWCPFwdBus()
    {
        if (!WheelchairPassengersMovingBusesForward.isEmpty() && (!WheelchairPassengersMovingBusesForward.peek()->checkAddPassenger() || !BusNeeded(WheelchairPassengersMovingBusesForward.peek())))
        {
            return WheelchairPassengersMovingBusesForward.dequeue();
        }
        else
            return nullptr;
    }
    Bus *removeNPBwdBus()
    {
        if (!NormalPassengersMovingBusesBackward.isEmpty() && (!NormalPassengersMovingBusesBackward.peek()->checkAddPassenger() || !BusNeeded(NormalPassengersMovingBusesBackward.peek())))
        {
            return NormalPassengersMovingBusesBackward.dequeue();
        }
        else
            return nullptr;
    }
    Bus *removeWCPBwdBus()
    {
        if (!WheelchairPassengersMovingBusesBackward.isEmpty() && (!WheelchairPassengersMovingBusesBackward.peek()->checkAddPassenger() || !BusNeeded(WheelchairPassengersMovingBusesBackward.peek())))
        {
            return WheelchairPassengersMovingBusesBackward.dequeue();
        }
        else
            return nullptr;
    }
};