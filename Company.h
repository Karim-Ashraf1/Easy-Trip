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
#include "UI.h"
#include "Time.h"
#include "Functions.h"
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
    LinkedQueue<Passenger *> FinishList;

    UI ui;

    int checkup_durations_Wb;
    int checkup_durations_Mb;
    int TimeFromStationToStation;
    int numberOfStations;
    int promotedPassengers;
    int MaxWaitingTime;
    int JourneysToCheckup;
    int MixedBusCapacity;
    int WheelBusCapacity;
    int BoardingTime;
    int NumberOfEvents;

    // class' functions
    // function to Enque busess to a queue according to their number from the inout file
    void EnqueueGarage(int WbusCount, int MbusCount, int journeysToCheckup)
    {

        // create objects according to number of busses available
        for (int i = 0; i < MbusCount; i++)
        {
            Bus *MixedBus = new Bus("MBus", MixedBusCapacity, JourneysToCheckup);
            GarageQueue.enqueue(MixedBus);
        }

        for (int i = 0; i < WbusCount; i++)
        {
            Bus *MixedBus = new Bus("WBus", WheelBusCapacity, JourneysToCheckup);
            GarageQueue.enqueue(MixedBus);
        }
    }

    Events *CreateArrive(ifstream &file)
    {
        string PassengerType;
        int hour, minute, id, startStation, EndStation, Priority = -1;
        char colon;
        file >> PassengerType >> hour >> colon >> minute >> id >> startStation >> EndStation;
        if (PassengerType == "SP")
        {
            string subType;
            file >> subType;
            if (subType == "aged")
            {
                Priority = 2;
            }
            else if (subType == "POD")
            {
                Priority = 1;
            }
            else
            {
                Priority = 0;
            }
        }
        int time = hour * 60 + minute;
        return new Arrive(time, id, PassengerType, startStation, EndStation, Priority);
    }

    Events *CreateLeave(ifstream &file)
    {
        int hour, min, id;
        char colon;
        file >> hour >> colon >> min >> id;
        int time = hour * 60 + min;
        return new Leave(numberOfStations, id, time);
    }

    void GetPassengersOff(int time, string Filename)
    {
        for (int i = 0; i < numberOfStations; i++)
        {
            Station Station = StationsArray[i];
            // Loop through NormalPassengersMovingBusesForward

            while (!Station.getNormalPassengersMovingBusesForward().isEmpty())
            {
                Bus *bus = Station.getNormalPassengersMovingBusesForward().dequeue();
                Bus Bus = *bus;
                Bus.checkEndStationAndRemove(Station, Filename, time, FinishList, BoardingTime);
            }

            // Loop through NormalPassengersMovingBusesBackward

            while (!Station.getNormalPassengersMovingBusesBackward().isEmpty())
            {
                Bus *bus = Station.getNormalPassengersMovingBusesBackward().dequeue();
                Bus Bus = *bus;
                Bus.checkEndStationAndRemove(Station, Filename, time, FinishList, BoardingTime);
            }

            // Loop through WheelchairPassengersMovingBusesForward
            ;
            while (!Station.getWheelchairPassengersMovingBusesForward().isEmpty())
            {
                Bus *bus = Station.getWheelchairPassengersMovingBusesForward().dequeue();
                Bus Bus = *bus;
                Bus.checkEndStationAndRemove(Station, Filename, time, FinishList, BoardingTime);
            }

            // Loop through WheelchairPassengersMovingBusesBackward

            while (!Station.getWheelchairPassengersMovingBusesBackward().isEmpty())
            {
                Bus *bus = Station.getWheelchairPassengersMovingBusesBackward().dequeue();
                Bus Bus = *bus;
                Bus.checkEndStationAndRemove(Station, Filename, time, FinishList, BoardingTime);
            }
        }
    }

    void boardPassengers(int time, string Filename)
    {
        for (int i = 0; i < numberOfStations; i++)
        {
            Station Station = StationsArray[i];
            // Loop through NormalPassengersMovingBusesForward

            while (!Station.getNormalPassengersMovingBusesForward().isEmpty())
            {
                Bus *bus = Station.getNormalPassengersMovingBusesForward().dequeue();
                Bus Bus = *bus;
                Bus.boardPassengers(Station, Filename, time, MixedBusCapacity, WheelBusCapacity, BoardingTime);
            }

            // Loop through NormalPassengersMovingBusesBackward

            while (!Station.getNormalPassengersMovingBusesBackward().isEmpty())
            {
                Bus *bus = Station.getNormalPassengersMovingBusesBackward().dequeue();
                Bus Bus = *bus;
                Bus.boardPassengers(Station, Filename, time, MixedBusCapacity, WheelBusCapacity, BoardingTime);
            }

            // Loop through WheelchairPassengersMovingBusesForward

            while (!Station.getWheelchairPassengersMovingBusesForward().isEmpty())
            {
                Bus *bus = Station.getWheelchairPassengersMovingBusesForward().dequeue();
                Bus Bus = *bus;
                Bus.boardPassengers(Station, Filename, time, MixedBusCapacity, WheelBusCapacity, BoardingTime);
            }

            // Loop through WheelchairPassengersMovingBusesBackward

            while (!Station.getWheelchairPassengersMovingBusesBackward().isEmpty())
            {
                Bus *bus = Station.getWheelchairPassengersMovingBusesBackward().dequeue();
                Bus Bus = *bus;
                Bus.boardPassengers(Station, Filename, time, MixedBusCapacity, WheelBusCapacity, BoardingTime);
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

    void PromotePassengers(int time)
    {
        for (int i = 0; i < numberOfStations; i++)
        {
            StationsArray[i].promotePassenger(time, MaxWaitingTime);
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
    void AddToFinishList(Passenger psngr)
    {
        Passenger *pntr;
        pntr = &psngr;
        FinishList.enqueue(pntr);
    }
    void Output()
    {
        ofstream outFile("output.txt");
        outFile << "FT\t\t\t\tID\t\t\t\tAT\t\t\t\tWT\t\t\t\tTT" << endl; // FT -> Finish Time  AT -> Arrival Time  WT -> Waiting Time  TT -> Trip Time
        int NPCount = 0, SPCount = 0, WPCount = 0, TotalWait = 0, TotalPass = 0, TotalTrip = 0, MBus = 0, WBus = 0, totalBuses = 0, totalUtilize = 0, totalBusyTime = 0;
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
            totalBusyTime += bus->BusBusyTime();
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
        outFile << "Avg Busy Time : " << totalBusyTime / totalBuses * 100 << "%\n";
        outFile << "Avg Utilization : " << totalUtilize / totalBuses * 100 << "%\n";
    }

public:
    LinkedQueue<Passenger *> &getFinishlist()
    {
        return FinishList;
    }

    void ReadFile(string fileName)
    {
        // Read Number Of Station
        numberOfStations = *(ConvertToInt(GetFileLine(fileName, 1, 'O')));
        // Read Time Between Stations
        TimeFromStationToStation = *(ConvertToInt(GetFileLine(fileName, 1, 'O')) + 1);
        StationsArray = new Station[numberOfStations];
        for (int i = 0; i < numberOfStations; i++)
        {
            StationsArray[i] = Station(i, TimeFromStationToStation);
        }
        // Read Number Of Mixed Busses
        int MixedBusCount, WheelBusCount;
        MixedBusCount = *(ConvertToInt(GetFileLine(fileName, 2, 'O')) + 1);
        // Read Number Of Mixed Busses
        WheelBusCount = *(ConvertToInt(GetFileLine(fileName, 2, 'O')));
        // Read Capacity of Mixed Bus
        MixedBusCapacity = *(ConvertToInt(GetFileLine(fileName, 3, 'O')));
        // Read Capacity of Wheel Bus
        WheelBusCapacity = *(ConvertToInt(GetFileLine(fileName, 3, 'O')) + 1);
        // Read Number of jornyes needed before Checkup
        JourneysToCheckup = *(ConvertToInt(GetFileLine(fileName, 4, 'O')));
        // Read duration of checkup for Wbus
        checkup_durations_Wb = *(ConvertToInt(GetFileLine(fileName, 4, 'O')) + 1);
        // Read duration of checkup for Mbus
        checkup_durations_Mb = *(ConvertToInt(GetFileLine(fileName, 4, 'O')) + 2);
        EnqueueGarage(WheelBusCount, MixedBusCount, JourneysToCheckup);
        // Read MAx Waiting Time
        MaxWaitingTime = *(ConvertToInt(GetFileLine(fileName, 5, 'O')));
        // Read Boarding Time
        BoardingTime = *(ConvertToInt(GetFileLine(fileName, 5, 'O')) + 1);
        // Read Number OF Events
        NumberOfEvents = *(ConvertToInt(GetFileLine(fileName, 6, 'O')));
        // Read File Events
        GetFileLine(fileName, 7, 'E');
    }

    string *GetFileLine(string &fileName, int lineNum, char Functionality /*E to read Events, O to read only this line*/)
    {
        // Use the ifstream object file to read the file
        ifstream file;
        // filename will store the name of the file and line_number the line number
        string filename = fileName;
        int Capacity = *(CalcCapacity(filename));
        string *FileArray = new string[Capacity]; // to be changed to linked list
        int line_number = lineNum;

        // Open the file with the provided filename
        file.open(filename);

        // If there was a failure opening the file (perhaps it does not exist) then
        // exit with an error message and status.
        if (file.fail())
        {
            cout << "File failed to open." << endl;
            return 0;
        }

        int current_line = 0;
        string line;

        // Continue to read the file one line at a time, unless we reach the end of
        while (!file.eof())
        {
            // Increment the current line number being read as we are reading in the
            current_line++;

            // Read the next line from the 'file' into the 'line' string
            getline(file, line);

            if (Functionality == 'O')
            {
                // If current line number of the line we've read in matches the line number
                // that we're looking for, use break to stop the loop
                if (current_line == line_number)
                    FileArray = SplitString(line); // to be fixed when linked list
                break;
            }
            if (Functionality == 'E')
            {
                while (NumberOfEvents <= 0)
                {
                    char EventType;
                    file >> EventType;
                    Events *Event = EventType == 'A' ? CreateArrive(file) : CreateLeave(file);
                    EventsList.enqueue(Event);
                }
            }
        }
        file.close();
        return FileArray;
    }

    void Simulate(const string &fileName)
    {
        ui.Mode();
        int time = 240;     // Equivelent to 4 oclock
        while (time < 1320) // loop while time is between 4 am oclock and 10 pm oclock
        {
            MoveBusFromGarage(time); //  bus from station #0 to movingbusses list

            removeBusFromCheckup(time, checkUpMixedBus, checkup_durations_Mb);  //  bus from movingbusses list to waiting in station
            removeBusFromCheckup(time, checkUpWheeldBus, checkup_durations_Wb); //  bus from movingbusses list to waiting in station

            addBusToStation(time); // Adding busses to their equivalent station

            EventExcute(time); // Excutes which Event has been received

            PromotePassengers(time); // promotion from np to sp

            GetPassengersOff(time, fileName); // loop through all busses in all stations and remove the passengers that have arrived at their destanation
            boardPassengers(time, fileName);  // loop through all the busses an all the stations and board the passengers

            ui.PrintSimulation(time, StationsArray, numberOfStations, FinishList, checkUpMixedBus, checkUpMixedBus, Moving_Busses); // print output screen

            time++; //  increment time
        }
    }

    void addToMovingListNP(int time)
    {
        for (int i = 0; i < numberOfStations; i++)
        {
            Bus *bus = StationsArray[i].removeNPFwdBus();
            if (bus)
            {
                bus->setMovingTime(time);
                Moving_Busses.enqueue(bus);
            }
            bus = StationsArray[i].removeNPBwdBus();
            if (bus)
            {
                bus->setMovingTime(time);
                Moving_Busses.enqueue(bus);
            }
        }
    }

    void addToMovingListWCP(int time)
    {
        for (int i = 0; i < numberOfStations; i++)
        {
            Bus *bus = StationsArray[i].removeWCPFwdBus();
            if (bus)
            {
                bus->setMovingTime(time);
                Moving_Busses.enqueue(bus);
            }
            bus = StationsArray[i].removeWCPBwdBus();
            if (bus)
            {
                bus->setMovingTime(time);
                Moving_Busses.enqueue(bus);
            }
        }
    }
};