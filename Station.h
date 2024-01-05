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
    LinkedList<Passenger *> NormalWaitingPassFwd; /* not the best data structure was needed to implement promotePassenger function*/
    LinkedList<Passenger *> NormalWaitingPassBwd;
    PriorityQueue<Passenger> SpecialWaitingPassFwd;
    PriorityQueue<Passenger> SpecialWaitingPassBwd;
    LinkedQueue<Passenger> WChairWaitingPassFwd;
    LinkedQueue<Passenger> WChairWaitingPassBwd;
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

    void setNormalWaitingPassengersForward(const LinkedList<Passenger> &passengers)
    {
        NormalWaitingPassFwd = passengers;
    }
    void setNormalWaitingPassengersBackrward(const LinkedList<Passenger> &passengers)
    {
        NormalWaitingPassBwd = passengers;
    }
    void setSpecialWaitingPassengersForward(const PriorityQueue<Passenger> &passengers)
    {
        SpecialWaitingPassFwd = passengers;
    }
    void setSpecialWaitingPassengersBackward(const PriorityQueue<Passenger> &passengers)
    {
        SpecialWaitingPassBwd = passengers;
    }
    void setWheelchairWaitingPassengersForwards(const LinkedQueue<Passenger> &passengers)
    {
        WChairWaitingPassFwd = passengers;
    }
    void setWheelchairWaitingPassengersBackwards(const LinkedQueue<Passenger> &passengers)
    {
        WChairWaitingPassBwd = passengers;
    }
    void setAvailableBusses(const LinkedQueue<Bus *> &busses)
    {
        AvailableBuses = busses;
    }

    LinkedList<Passenger> &getNormalWaitingPassengersForward()
    {
        return NormalWaitingPassFwd;
    }
    LinkedList<Passenger> &getNormalWaitingPassengersBackward()
    {
        return NormalWaitingPassBwd;
    }
    PriorityQueue<Passenger> &getSpecialWaitingPassengersForward()
    {
        return SpecialWaitingPassFwd;
    }
    PriorityQueue<Passenger> &getSpecialWaitingPassengersBackward()
    {
        return SpecialWaitingPassBwd;
    }
    LinkedQueue<Passenger> &getWheelchairWaitingPassengersForwards()
    {
        return WChairWaitingPassFwd;
    }
    LinkedQueue<Passenger> &getWheelchairWaitingPassengersBackwards()
    {
        return WChairWaitingPassBwd;
    }
    LinkedQueue<Bus *> &getAvailableBusses()
    {
        return AvailableBuses;
    }
    LinkedList<Passenger *> &getFinishlist()
    {
        return FinishList;
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

    void moveBusFromMovingToWaiting()
    {
    }

    void busFromMovingToWaiting(DoubleLinkedList<Station *> &stationsList, Station &currentStation)
    {

        Node<Station *> *waitingStation = stationsList.Find(&currentStation); // Find the current station in the linked list

        if (waitingStation != nullptr)
        {
            // currentStation.getAvailableBusses().enqueue(*this); // add the bus to the current station's
        }
    }

    void moveBusFromWatingToMoving()
    {
        Bus *b;
        if (!AvailableBuses.isEmpty())
        {
            AvailableBuses.peek(b);
            AvailableBuses.dequeue(b);
            b->boardPassengers(*this);
            movingBusses.enqueue(b);
        }
        else
        {
            cout << "No Busses is waiting";
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
                NormalWaitingPassFwd.InsertEnd(*psngr);
            }
            else
            {
                NormalWaitingPassBwd.InsertEnd(*psngr);
            }
        }
        else if (PassengerType == "SP")
        {
            if (psngr->getStartStation() < psngr->getEndStation())
            {
                SpecialWaitingPassFwd.priorityEnqueue(*psngr);
            }
            else
            {
                SpecialWaitingPassBwd.priorityEnqueue(*psngr);
            }
        }
        if (PassengerType == "WP")
        {
            if (psngr->getStartStation() < psngr->getEndStation())
            {
                WChairWaitingPassFwd.enqueue(*psngr);
            }
            else
            {
                WChairWaitingPassBwd.enqueue(*psngr);
            }
        }
    }

    int promotePassenger(int time, int maxW)
    {
        int promotedPassCount = 0;
        LinkedQueue<Passenger *> promotePassengers;
        for (auto passenger : NormalWaitingPassFwd)
        {
            int waitingTime = time - passenger->getArrival();
            if (waitingTime > maxW)
            {
                promotedPassCount++;
                promotePassengers.enqueue(passenger);
            }
        }
        while (!promotePassengers.isEmpty())
        {
            Passenger *passenger = promotePassengers.dequeue();
            NormalWaitingPassFwd.DeleteNode(passenger);
            SpecialWaitingPassFwd.priorityEnqueue(passenger);
        }
        for (auto passenger : NormalWaitingPassBwd)
        {
            int waitingTime = time - passenger->getArrival();
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
            SpecialWaitingPassBwd.priorityEnqueue(passenger);
        }

        return promotedPassCount;
    }
};
