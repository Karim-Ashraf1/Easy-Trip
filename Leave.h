#include <iostream>
#include <Station.h>
#include <Passenger.h>
#include <DoubleLinkedList.h>
#include <LinkedQueue.h>
#include <Arrive.h>
#include <Events.h>
using namespace std;

class Leave_Event : public Events
{
private:
    bool L;        // means this is a LEAVE event line
    int ET;        // event timestep
    int ID;        // id if the passengerswho decided to leave
    int STRT;      // start station of the passenger asking to leave
    Passenger *LP; // LP= Leaving Passenger
    //Passenger *DP; // DP= Dequeued Passenger
public:
    // setters for all attrubiutes of Leave
    void SetID(int id) { ID = id; }
    void SetStartStation(int start) { STRT = start; }
    void setEventTimeStep(int et) { ET = et; }
    void setL(int l) { L = l; }
    void set_LP(Passenger* p){LP=p;}

    /// getters for all attrubiutes of Leave
    int GetID() const { return ID; }
    int GetStartStation() const { return STRT; }
    int GetEventTimeStep() const { return ET; }
    int GetLeaveEvent() const { return L; }
    Passenger* Get_LP() const {return LP;}

    /// overloaded Excute() in Events class
    void Execute(int FileArray[])
    {
        DoubleLinkedList<Passenger *> Passwait;               // List of pointers to passengers
        Passwait.DeleteNodeVal(Passwait.FindPassenger(LP)); //  // delete the leaving passenger if found in passengers
    }
};