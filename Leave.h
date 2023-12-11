#include <iostream>
#include <Station.h>
#include <Passenger.h>
#include <DoubleLinkedList.h>
#include <LinkedQueue.h>
#include <Arrive.h>
using namespace std;

class Leave_Event
{
private:
    bool L;        // means this is a LEAVE event line
    int ET;        // event timestep
    int ID;        // id if the passengerswho decided to leave
    int STRT;      // start station of the passenger asking to leave
    Passenger *LP; // LP= Leaving Passenger
    Passenger *DP; // DP= Dequeued Passenger
public:
    // setters for all attrubiutes of Leave
    void SetID(int id) { ID = id; }
    void SetStartStation(int start) { STRT = start; }
    void setEventTimeStep(int et) { ET = et; }
    void setL(int l){L=l;}

    /// getters for all attrubiutes of Leave
    int GetID() const { return ID; }
    int GetStartStation() const { return STRT; }
    int GetEventTimeStep() const { return ET; }
    int GrtLeaveEvent() const {return L;}
    
    /// overloaded Excute() in Events class
    void Execute()
    {
        DoubleLinkedList<Passenger *> appropiate;               // List of pointers to passengers
        appropiate.DeleteNodeVal(appropiate.FindPassenger(LP)); //  // delete the leaving passenger if found in passengers
    }
};