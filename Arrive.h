#include<iostream> 
#include<Station.h>
#include<Passenger.h>
using namespace std;

class Arrive{
private:
    Passenger Psngr ; // Creating a Passenger instance 
    int ET ; // Event timestep
    int ID ; // Unique number that identifies each passenger
    Station Stn ; // Create a station instance
protected:
    void Execute();
};