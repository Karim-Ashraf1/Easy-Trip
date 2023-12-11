#include <Station.h>

int main() {

    Station myStation(1, 2);

    Bus myBus;
    myStation.addBus(myBus);

    Passenger passenger1;
    passenger1.setId(1);
    passenger1.setStartStation(1);
    passenger1.setEndStation(5);
    passenger1.setOnTime(Time(10, 30, 0));
    passenger1.setOFFTime(Time(12, 0 ,0));
    passenger1.setType("WP");

    myStation.AddToFinishList(passenger1);

    myStation.printFinishListAttributes();

    return 0;
}
