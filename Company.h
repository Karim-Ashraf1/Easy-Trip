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
    LinkedQueue <Events*> EventsList;
    DoubleLinkedList <Station*> StationsList;
    LinkedQueue<Bus*> GarageQueue;
public:


    // function to Enque busess to a queue according to their number from the inout file
    LinkedQueue<Bus*> EnqueueGarage(const string& fileName)
    {
        LinkedQueue<Bus*> BusQueue;
        int* BussesNumber;

        BussesNumber=ConvertToInt(GetFileLine(fileName,2,'O'));

    //  functions to create objects according to number of busses available
        for (int i=0; i < *(BussesNumber); i++)
        {
            Bus *MixedBus = new Bus ();
            MixedBus->setDirection('F');
            MixedBus->setId(i);
            MixedBus->setType("MB");
            BusQueue.enqueue(MixedBus);
        }

        for (int i=0; i < *(BussesNumber+1); i++)
        {
            Bus *WheelChairBus = new Bus ();
            WheelChairBus->setDirection('F');
            WheelChairBus->setId(i);
            WheelChairBus->setType("WB");
            BusQueue.enqueue(WheelChairBus);
        }
        return BusQueue;
    }


    // to be modified later
    int StartProgram(string fileName){
        
        
        string* ArrayPtr=GetFileLine(fileName,7,'R');

        int FileArray[10]; //to be modified into linked list


        if (*ArrayPtr == "A")
        {
            //arival.Execute(ArrayPtr); // to be fixed when changed to linked list
        }
        if (*ArrayPtr == "L"){
            //Leave.Execute(ArrayPtr); // to be fixed when changed to linked list
        }
    }

    void Simulate() {

        // loop in company
            // 1) bus from station #0 to movingbusses list
            // 2) from checkup to movingbusses list
            // 3) bus from movingbusses list to waiting in station
        // loop in stations
            // 4) promotion from np to sp
            // 5) if there is leave event will remove the passenger
            // 6) arrival event if there is arival passengers
        // loop in busses
            // 7) passengers getoff to finish list
            // 8) check if the bus need checkup if yes will go to checkup if no step 9 will happen
            // 9) boarding passengers accourding to their piriority
            // 10) bus from waiting in station to movingbusses list
            // 11) 

    }
};