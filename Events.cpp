#include<Events.h>
#include<Leave.h>
#include<Arrive.h>

int main() {

    Arrive arriveEvent;
    int FileArray[7];
    arriveEvent.SetID(2);
    arriveEvent.SetStartStation(1);
    arriveEvent.SetEndStation(4);
    arriveEvent.SetOnTime(10);
    arriveEvent.SetOffTime(15);
    arriveEvent.SetType("SP");

    arriveEvent.Execute(FileArray);

/////////////////////////////////////////////////////

    Leave_Event leaveEvent;
    
    leaveEvent.SetID(1);
    leaveEvent.SetStartStation(3);
    leaveEvent.setEventTimeStep(5);
    leaveEvent.setL(true);

    Passenger leavingPassenger;
    leaveEvent.set_LP(&leavingPassenger);

    leaveEvent.Execute(FileArray);

    return 0;
}
