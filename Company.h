#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Events.h"
#include "Leave.h"
#include "Bus.h"
#include "Station.h"
#include "LinkedQueue.h"
#include "DoubleLinkedList.h"
#include "UI.h"
#include "Time.h"
#include "Function.h"
#include <Functions.h>
using namespace std;

class Company
{
private:
    Station *StationsArray;
    LinkedQueue<Events *> EventsList;
    LinkedQueue<Bus *> GarageQueue;
    LinkedQueue<Bus *> Moving_Busses;
    LinkedQueue<Bus *> checkUpMixedBus;
    LinkedQueue<Bus *> checkUpWheeldBus;
    LinkedQueue<Bus *> BusQueue;
    LinkedQueue<Passenger *> FinishList;

    UI ui;

    int checkup_durations_Wb;
    int checkup_durations_Mb;
    int TimeFromStationToStation;
    int numberOfStations;
    int promotedPassengers;
    int MaxWaitingTime;

    // class' functions

    void boardPassengers(int time, string Filename)
	{
		for (int i = 0; i < numberOfStations; i++) {
            Station Station=StationsArray[i];
            // Loop through NormalPassengersMovingBusesForward
            LinkedQueue<Bus *> &normalMovingBusesForward = Station.getNormalPassengersMovingBusesForward();
                while (!normalMovingBusesForward.isEmpty()) {
                 Bus *bus = normalMovingBusesForward.dequeue();
                 Bus Bus=*bus;
                Bus.boardPassengers(Station,Filename,time);
                }

                // Loop through NormalPassengersMovingBusesBackward
            LinkedQueue<Bus *> &normalMovingBusesBackward =Station.getNormalPassengersMovingBusesBackward();
            while (!normalMovingBusesBackward.isEmpty()) {
                Bus *bus = normalMovingBusesBackward.dequeue();
                Bus Bus=*bus;
                Bus.boardPassengers(Station,Filename,time);
            }             

                // Loop through WheelchairPassengersMovingBusesForward
            LinkedQueue<Bus *> &wheelchairMovingBusesForward = Station.getWheelchairPassengersMovingBusesForward();
                while (!wheelchairMovingBusesForward.isEmpty()) {
                    Bus *bus = wheelchairMovingBusesForward.dequeue();
                    Bus Bus=*bus;
                    Bus.boardPassengers(Station,Filename,time);
                }

                // Loop through WheelchairPassengersMovingBusesBackward
            LinkedQueue<Bus *> &wheelchairMovingBusesBackward = Station.getWheelchairPassengersMovingBusesBackward();
                while (!wheelchairMovingBusesBackward.isEmpty()) {
                    Bus *bus = wheelchairMovingBusesBackward.dequeue();
                    Bus Bus=*bus;
                    Bus.boardPassengers(Station,Filename,time);
                }


            }
        
    };

    void MoveBusFromGarage(int Time)
    {
        if (Time < 240)
            return;
        if (Time % 15 == 0 && !Moving_Busses.isEmpty())
        {
            Bus *BussCheck;
            BussCheck = GarageQueue.dequeue();
            BussCheck->setMovingTime(Time);
            StationsArray[0].addBusses(BussCheck);
        }
    }

    void AddBusToCheckup(int time, Bus *bus)
    {
        bus->setBusMaintenanceTime(time);
        if (bus->getType() == "MBus")
        {
            checkUpMixedBus.enqueue(bus);
        }
        else
        {
            checkUpWheeldBus.enqueue(bus);
        }
    }


    void PromotePassengers(int time){
        for (int i = 0; i < numberOfStations; i++){
            StationsArray[i].promotePassenger(time,MaxWaitingTime);
        }
    }
    // a function to remove all busses that are done with their checkup and add one minute to the busses that aren't done
    void removeBusFromCheckup(int time, LinkedQueue<Bus *> &busCheckupQueue, int checkUpTime)
    {
        while (!busCheckupQueue.isEmpty() && time - busCheckupQueue.peek()->getBusMaintenanceTime() == checkUpTime) // checks if the bus to dequed finished its checkup
        {
            Bus *bus;
            bus = busCheckupQueue.dequeue();
            bus->setChekup(false);
            bus->setDirection('F');
            StationsArray[0].addBusses(bus);
        }
    }

    void addBusToStation(int time)
    {
        while (!Moving_Busses.isEmpty() && time - Moving_Busses.peek()->getMovingTime() == TimeFromStationToStation)
        {
            Bus *bus = Moving_Busses.dequeue();
            int currentStation = bus->getCurrentStation();
            int nextStation = (bus->getdirection() == 'F') ? 1 : -1; // if forward it will increment one station if backward it will decrement one station
            nextStation = nextStation + currentStation;
            bus->setCurrentStation(nextStation);
            if (nextStation <= numberOfStations - 1 || nextStation == 0)
            {
                StationsArray[nextStation].addBusses(bus);
            }
            else if (StationsArray[nextStation].BusNeeded(bus) || bus->PassengerOff())
            {
                StationsArray[nextStation].addBusses(bus);
            }
            else
            {
                bus->setMovingTime(time);
                Moving_Busses.enqueue(bus);
            }
        }
    }

    void EventExcute(int Time)
    {
        if (Time > 1320) // 1320 = 22:00 which is when the company is closed
            return;
        while (!EventsList.isEmpty() && EventsList.peek()->getTime() == Time)
            EventsList.dequeue()->Execute(StationsArray);
    }

public:
    LinkedQueue<Passenger *> &getFinishlist()
    {
        return FinishList;
    }
    void AddToFinishList(Passenger psngr)
    {
        Passenger *pntr;
        pntr = &psngr;
        FinishList.enqueue(pntr);
    }
    void Simulate(const string &fileName)
    {
        ui.Mode();
        int time = 0;
        // loop in company
        while (time > 240 && time < 1320) // loop while time is between 4 am oclock and 10 pm oclock
        {
            MoveBusFromGarage(time); //  bus from station #0 to movingbusses list

            removeBusFromCheckup(time, checkUpMixedBus, checkup_durations_Mb);  //  bus from movingbusses list to waiting in station
            removeBusFromCheckup(time, checkUpWheeldBus, checkup_durations_Wb); //  bus from movingbusses list to waiting in station

            addBusToStation(time); // Adding busses to their equivalent station

            EventExcute(time); // Excutes which Event has been received
            
            PromotePassengers(time);// promotion from np to sp
            // loop in busses
            // 7) passengers getoff to finish list
            // 8) check if the bus need checkup if yes will go to checkup if no step 9 will happen
            // 9) boarding passengers accourding to their piriority
            // 10) bus from waiting in station to movingbusses list
            // 11) print output screen
            boardPassengers(time, fileName);//loop through all the busses an all the stations and board the passengers
            ui.PrintSimulation(time, StationsArray, numberOfStations, FinishList, checkUpMixedBus, checkUpMixedBus, Moving_Busses);

            time++; //  increment time
        }
    }

    void Output()
    {
        ofstream outFile("output.txt");
        outFile << "FT\t\t\t\tID\t\t\t\tAT\t\t\t\tWT\t\t\t\tTT" << endl; // FT -> Finish Time  AT -> Arrival Time  WT -> Waiting Time  TT -> Trip Time
        int NPCount = 0, SPCount = 0, WPCount = 0, TotalWait = 0, TotalPass = 0, TotalTrip = 0, MBus = 0, WBus = 0, totalBuses = 0, totalUtilize = 0;
        while (!FinishList.isEmpty())
        {
            Passenger *pass = FinishList.dequeue();
            outFile << FromTotalMinutesToString(pass->getOFFTime()) << "\t\t\t\t";
            outFile << FromTotalMinutesToString(pass->getId()) << "\t\t\t\t";
            outFile << FromTotalMinutesToString(pass->getArrival()) << "\t\t\t\t";
            outFile << FromTotalMinutesToString(pass->getWaitingTime()) << "\t\t\t\t";
            outFile << FromTotalMinutesToString(pass->getOFFTime() - pass->getArrival()) << "\t\t\t\t\n";

            TotalWait += pass->getWaitingTime();
            TotalTrip += (pass->getOFFTime() - pass->getArrival());
            string passType = pass->getType();
            if (passType == "NP")
            {
                NPCount++;
            }
            else if (passType == "SP")
            {
                SPCount++;
            }
            else
            {
                WPCount++;
            }
        }
        while (!GarageQueue.isEmpty())
        {
            Bus *bus = GarageQueue.dequeue();
            string busType = bus->getType();
            totalUtilize += bus->BusUtilization();
            if (busType == "MBus")
            {
                MBus++;
            }
            else
            {
                WBus++;
            }
        }

        TotalPass = NPCount + SPCount + WPCount;
        outFile << "Total Passengers : " << TotalPass << "\t {NP :" << NPCount << "\t SP :" << SPCount << "\t WP :" << WPCount << "}\n";
        outFile << "Avg Waiting Time for Passengers : " << FromTotalMinutesToString(TotalWait / TotalPass) << "\n";
        outFile << "Avg Trip Time for Passengers : " << FromTotalMinutesToString(TotalTrip / TotalPass) << "\n";
        outFile << "Auto Promoted Passengers : " << promotedPassengers / TotalPass * 100 << "%\n";

        totalBuses = MBus + WBus;
        outFile << "Buses : " << totalBuses << "\t {MBus :" << MBus << "\t WBus :" << WBus << "}\n";
        outFile << "Avg Utilization : " << totalUtilize / totalBuses * 100 << "%\n";
    }
    string FromTotalMinutesToString(int totalMinutes)
    {
        Time resultTime;

        // Calculate hours and minutes
        resultTime.setHours(totalMinutes / 60 % 24);
        resultTime.setMinutes(totalMinutes % 60);
        std::ostringstream oss;

        // Format the hours and minutes with leading zeros if needed
        oss << std::setw(2) << std::setfill('0') << resultTime.getHours() << ":"
            << std::setw(2) << std::setfill('0') << resultTime.getMinutes();

        return oss.str();
    }
};