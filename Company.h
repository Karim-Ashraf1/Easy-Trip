#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Events.h"
#include "Leave.h"
#include "Bus.h"
#include "Station.h"
#include "LinkedQueue.h"
#include "DoubleLinkedList.h"
#include "UI.h"
#include "Function.h"
#include <Functions.h>
using namespace std;

class Company {
private:
    Station* StationsArray;
    LinkedQueue <Events*> EventsList;
    LinkedQueue<Bus*> GarageQueue;
    LinkedQueue<Bus*>Moving_Busses;
    LinkedQueue<Bus*>checkUpMixedBus;
    LinkedQueue<Bus*>checkUpWheeldBus;
    LinkedQueue<Bus*> BusQueue;

    int no_of_stations;
    int time_between_stations;
    int no_of_WBuses; 
    int no_of_MBuses;
    int Capacity_of_Wbus_bus;
    int Capacity_of_Mbus_bus;
    int no_of_trips_before_checkup; 
    int checkup_durations_Wb;
    int checkup_durations_Mb;
    int maxW_minutes;
    int get_on_or_off_time_seconds;
    int no_of_events_in_the_file;



    //class' functions
    void MoveBusFromGarage(int Time){
            if(Time <240)
                return;
            if (Time % 15==0 && !Moving_Busses.isEmpty()){
                Bus* BussCheck;
                GarageQueue.dequeue(BussCheck); 
                BussCheck->setMovingTime(Time);   
                StationsArray[0].addBusses(BussCheck);
            }
        }


    void AddBusToCheckup(int time,Bus* bus){
            bus->setBusMaintenanceTime(time);
            if(bus->getType()== "MBus"){
                checkUpMixedBus.enqueue(bus);
            }
            else{
                checkUpWheeldBus.enqueue(bus);
            }
            
        }

    void removeBusFromCheckup(int time,LinkedQueue<Bus*>& busCheckupQueue,int checkUpTime){
        Bus* peekBus;
        busCheckupQueue.peek(peekBus);
        while(!busCheckupQueue.isEmpty()&&time - peekBus->getBusMaintenanceTime()==checkUpTime)//checks if the bus to dequed finished its checkup
        {
            Bus* bus;
            busCheckupQueue.dequeue(bus);
            bus->setChekup(false);
            bus->setDirection('F');
            StationsArray[0].addBusses(bus);
        }
    }

    // function to Enque busess to a queue according to their number from the inout file
    void EnqueueGarage(const string& fileName)
    {
        int* BussesNumber;
        BussesNumber=ConvertToInt(GetFileLine(fileName,2,'O'));

    //  functions to create objects according to number of busses available
        for (int i=0; i < *(BussesNumber); i++)
        {
            Bus *MixedBus = new Bus ();
            MixedBus->setDirection('F');
            MixedBus->setId(i);
            MixedBus->setType("MBus");
            BusQueue.enqueue(MixedBus);
        }

        for (int i=0; i < *(BussesNumber+1); i++)
        {
            Bus *WheelChairBus = new Bus ();
            WheelChairBus->setDirection('F');
            WheelChairBus->setId(i);
            WheelChairBus->setType("WBus");
            BusQueue.enqueue(WheelChairBus);
        }
    }

    int EventExcute(const string &fileName){
        
        Arrive arival;
        Leave leave;
        string* ArrayPtr=GetFileLine(fileName,7,'R');
        if (*ArrayPtr == "A")
        {
            arival.Execute(ArrayPtr); // to be fixed when changed to linked list
        }
        if (*ArrayPtr == "L"){
            leave.Execute(ArrayPtr); // to be fixed when changed to linked list
        }
    }
public:

    // to be modified later
    


    void Simulate(const string& fileName) {


        string* arr1 = GetFileLine(fileName,1,'O'); //  no. of stations , no. of min between each 2 stations
        string* arr2 = GetFileLine(fileName,2,'O'); //  no. of WBuses , no. of MBuses
        string* arr3 = GetFileLine(fileName,3,'O'); //  Capacity of each bus type (WBus then MBus)
        string* arr4 = GetFileLine(fileName,4,'O'); //  no. of trips before checkup and the checkup durations
        string* arr5 = GetFileLine(fileName,5,'O'); //  maxW (minutes), get on/off time (seconds)
        string* arr6 = GetFileLine(fileName,6,'O'); //  no. of events in this file. This line should be followed by n lines
        string* arr7 = GetFileLine(fileName,7,'R'); //  read all the file


        no_of_stations = *ConvertToInt(arr1);
        time_between_stations = *ConvertToInt(arr1+1);
        no_of_WBuses = *ConvertToInt(arr2);
        no_of_MBuses = *ConvertToInt(arr2+1);
        Capacity_of_Wbus_bus = *ConvertToInt(arr3);
        Capacity_of_Mbus_bus = *ConvertToInt(arr3+1);
        no_of_trips_before_checkup = *ConvertToInt(arr4);
        checkup_durations_Wb = *ConvertToInt(arr4+1);
        checkup_durations_Mb = *ConvertToInt(arr4+2);
        maxW_minutes = *ConvertToInt(arr5);
        get_on_or_off_time_seconds = *ConvertToInt(arr5+1);
        no_of_events_in_the_file = *ConvertToInt(arr6);


        EnqueueGarage(fileName);
        int time=0;
        // loop in company
        while (time> 240 && time<1320) //loop while time is between 4 ocklock and 10 ocklock
        {
            MoveBusFromGarage(time);;//  bus from station #0 to movingbusses list
            removeBusFromCheckup( time,checkUpMixedBus,checkup_durations_Mb);//  bus from movingbusses list to waiting in station
            removeBusFromCheckup( time,checkUpWheeldBus,checkup_durations_Wb);//  bus from movingbusses list to waiting in station
            EventExcute(fileName);// Excutes which Event has been received
        // loop in stations
            // 4) promotion from np to sp
        // loop in busses
            // 7) passengers getoff to finish list
            // 8) check if the bus need checkup if yes will go to checkup if no step 9 will happen
            // 9) boarding passengers accourding to their piriority
            // 10) bus from waiting in station to movingbusses list
            // 11) print output screen
            
            
            
            time++;//  increment time 


        }


    }
};