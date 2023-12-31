#pragma once
#include "Company.h"

void MoveBus(LinkedQueue<Bus*> &GarageQueue){
    LinkedQueue<Bus*>Moving_WBus;
    LinkedQueue<Bus*>Moving_Mbus;
    Bus* BussCheck;
    Bus* BussArray[2];
    while(!GarageQueue.isEmpty()){ 
        GarageQueue.dequeue(BussCheck);
        if (BussCheck->getType() == "WB"){
            Moving_WBus.enqueue(BussCheck);
        }
        if (BussCheck->getType() == "MB"){
            Moving_Mbus.enqueue(BussCheck);
        }
    }    
}