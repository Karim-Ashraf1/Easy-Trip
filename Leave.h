#include<iostream>
#include<Station.h>
#include<Passenger.h>
using namespace std;

class Leave_Event{
private:
    bool L ; // means this is a LEAVE event line
    int ET ; // event timestep
    int ID ; //id if the passengerswho decided to leave
    Station STRT ; // start station of the passenger asking to leave
public:
    void Execute(){
        //to be implented later on
    }
};