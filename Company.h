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

    int checkup_durations_Wb;
    int checkup_durations_Mb;
    int TimeFromStationToStation;
    int numberOfStations;




    //class' functions
    void MoveBusFromGarage(int Time){
            if(Time <240)
                return;
            if (Time % 15==0 && !Moving_Busses.isEmpty()){
                Bus* BussCheck;
                BussCheck=GarageQueue.dequeue(); 
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
    // a function to remove all busses that are done with their checkup and add one minute to the busses that aren't done
    void removeBusFromCheckup(int time,LinkedQueue<Bus*>& busCheckupQueue,int checkUpTime){
        while(!busCheckupQueue.isEmpty()&&time - busCheckupQueue.peek()->getBusMaintenanceTime()==checkUpTime)//checks if the bus to dequed finished its checkup
        {
            Bus* bus;
            bus=busCheckupQueue.dequeue();
            bus->setChekup(false);
            bus->setDirection('F');
            StationsArray[0].addBusses(bus);
        }
    }

   
    void addBusToStation(int time){
        while(!Moving_Busses.isEmpty() && time - Moving_Busses.peek()->getMovingTime()  == TimeFromStationToStation){
            Bus* bus = Moving_Busses.dequeue();
            int currentStation = bus->getCurrentStation();
            int nextStation = (bus->getdirection()=='F') ? 1:-1;//if forward it will increment one station if backward it will decrement one station
            nextStation = nextStation + currentStation;
            bus->setCurrentStation(nextStation);
            if (nextStation <= numberOfStations -1 || nextStation == 0){
                StationsArray[nextStation].addBusses(bus);
            }
            else if (StationsArray[nextStation].BusNeeded(bus)){
                StationsArray[nextStation].addBusses(bus);
            }
            else if(bus->PassengerOff()){
                StationsArray[nextStation].addBusses(bus);
                bus->checkEndStationAndRemove(nextStation);
            }
            else {
                bus->setMovingTime(time);
                Moving_Busses.enqueue(bus);
            }
        }
    }




    void EventExcute(int Time){
        if (Time > 1320 ) //1320 = 22:00 which is when the company is closed
            return;
        while(!EventsList.isEmpty() && EventsList.peek()->getTime() == Time)
            EventsList.dequeue()->Execute(StationsArray);
    }
public:

    // to be modified later
    


    void Simulate(const string& fileName) {

        int time=0;
        // loop in company
        while (time> 240 && time<1320) //loop while time is between 4 ocklock and 10 ocklock
        {
            MoveBusFromGarage(time);;//  bus from station #0 to movingbusses list

            removeBusFromCheckup( time,checkUpMixedBus,checkup_durations_Mb);//  bus from movingbusses list to waiting in station
            removeBusFromCheckup( time,checkUpWheeldBus,checkup_durations_Wb);//  bus from movingbusses list to waiting in station

            addBusToStation(time);// Adding busses to their equivalent station

            EventExcute(time);// Excutes which Event has been received
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