#include<iostream>
using namespace std;
#include "Station.h"

class Events{
protected:
    int Time;
    int Id;    
public:
    Events(int Id,int Time) {
        this-> Id = Id;
        this-> Time = Time;
    }

    virtual void Execute(Station* StationsArray) =0 {
        //Pure virtual function to be executed by inherited classes
    }
    int getTime() { return Time; }
};



