#include<iostream>
#include<Station.h>
#include<Passenger.h>
using namespace std;

class Events{
private:
    
public:
    virtual void Execute() =0 {

    }
};

class Arrival_Event{
private:
    bool A ; // means this is a LEAVE event line
    Passenger TYP ; // passenger type
    int ET ; // event timestep
    int ID ; // unique number to identifies each passenger
    Station STRT ; // start station of the passenger
    Station END; //  end station of the passenger
public:
    void Execute(){

    }
};

class Leave_Event{
private:
    bool L ; // means this is a LEAVE event line
    int ET ; // event timestep
    int ID ; //id if the passengerswho decided to leave
    Station STRT ; // start station of the passenger asking to leave
public:
    void Execute(){

    }
};