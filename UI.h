#pragma once
#include <iostream>
#include <Passenger.h>
#include <Bus.h>
#include <Station.h>
#include <Events.h>
#include <LinkedQueue.h>
#include <PriorityQueue.h>
#include<Arrive.h>

class UI
{
private:
    bool IsSilent;

public:
    UI(){
        IsSilent = true;
    }
    void Mode(){
        cout << "Choose mode :" << endl << "1 - Interactive :" << endl << "2 - Silent :" << endl;
        int Mode;
        cin >> Mode;
        if (Mode == 1){
            IsSilent = false;
        }
    }
    void PrintSimulation(int time , Station* StationsArray,int numberOfStations,LinkedQueue<Passenger*>& FinishedPassenger,LinkedQueue<Bus*>CheckupWBus,LinkedQueue<Bus*>CheckupMbus,LinkedQueue<Bus*>MovingBus ){
        if(IsSilent){
            return;
        }
        cout << "Time =  "<< time/60 << ":" << time%60 <<endl;
        Node<Bus*> *MBusData= CheckupMbus.getFrontPtr();
        Node<Bus*> *WBusData= CheckupMbus.getFrontPtr();
        Node<Passenger*> *PassengerData= FinishedPassenger.getFrontPtr();

        while (MBusData!=nullptr)
        {
            cout<<MBusData->getItem()->getId()<<", ";
            MBusData=MBusData->getNext();
        }
        while (WBusData!=nullptr)
        {
            cout<<WBusData->getItem()->getId()<<", ";
            WBusData=WBusData->getNext();
        }
        cout <<"\n *******************************"<<endl;
        cout<<FinishedPassenger.getSize()<<"Finished Passengers : ";
        while (PassengerData!=nullptr)
        {
            cout<<PassengerData->getItem()->getId()<<", ";
            PassengerData=PassengerData->getNext();
        }
        cout<<endl;
        system("pause");
    }

    void EndMessage(){
        cout<<"Simulation Ended"<<endl<<"Generated Output File";
    }
};