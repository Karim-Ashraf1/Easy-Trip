#include<iostream>
#include<Station.h>
#include<Passenger.h>
using namespace std;

class Events{
private:
    
public:
    virtual void Execute() =0 {
        //Pure virtual function to be executed by inherited classes
    }
};



