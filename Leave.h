#include <iostream>
#include <Station.h>
#include <Passenger.h>
#include <LinkedList.h>
#include <LinkedQueue.h>
#include <Arrive.h>
using namespace std;

class Leave_Event
{
private:
    bool L;        // means this is a LEAVE event line
    int ET;        // event timestep
    int ID;        // id if the passengerswho decided to leave
    int STRT;  // start station of the passenger asking to leave
    Passenger *LP; // LP= Leaving Passenger
    Passenger *DP; // DP= Dequeued Passenger
public:

    // setters for all attrubiutes of Leave
    void SetID(int id){ID=id;}
    void SetStartStation(int start){STRT=start;}
    void setEventTimeStep(int et){ET=et;}


    /// getters for all attrubiutes of Leave
    int GetID() const {return ID;}
    int GetStartStation()const {return STRT;}
    int GetEventTimeStep() const {return ET;}

    /// overloaded Excute() in Events class
    void Execute()
    {
        LinkedList<Passenger *> appropiate;  // List of pointers to passengers
        LinkedQueue<Passenger *> leavequeue; // queue that will save passengers in bus until removing the leaving passenger

        // DP = appropiate.Find(LP); //
        // leavequeue.dequeue(DP);


    }
};