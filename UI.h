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
        for (Bus* bus : CheckupMbus){
            cout << bus->getId()<< ", ";
        }
        for (Bus* bus : CheckupWBus){
            cout << bus->getId()<<", ";
        }
        cout <<"\n *******************************"<<endl;
        cout<<FinishedPassenger.size()<<"Finished Passengers : ";
        for (auto Passenger : FinishedPassenger){
            cout<<Passenger->getId()<<", ";
        }
        cout<<endl;
        system("pause");
    }

    void EndMessage(){
        cout<<"Simulation Ended"<<endl<<"Generated Output File";
    }
};