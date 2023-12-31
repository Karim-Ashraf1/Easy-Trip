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
            MixedBus->setdirection('F');
            MixedBus->setId(i);
            MixedBus->setType("MB");
            BusQueue.enqueue(MixedBus);
        }

        for (int i=0; i < *(BussesNumber+1); i++)
        {
            Bus *WheelChairBus = new Bus ();
            WheelChairBus->setdirection('F');
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
};