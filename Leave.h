#include <iostream>
#include <Station.h>
#include <Passenger.h>
#include <DoubleLinkedList.h>
#include <LinkedQueue.h>
#include <Arrive.h>
#include <Events.h>
using namespace std;

class Leave : public Events
{
private:
   int numberOfStations;
public:
    Leave(int numberOfStations,int Id,int Time) : Events(Id,Time) ,numberOfStations(numberOfStations){}

    /// overloaded Excute() in Events class
    void Execute(Station* stationsArray)
    {
        for (int i = 0; i < numberOfStations;i++){
            stationsArray[i].PassengerLeave(Id); 
        }
    }
};