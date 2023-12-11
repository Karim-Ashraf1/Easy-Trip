#include <Bus.h>
#include<time.h>
using namespace std;

int main() {
    Time T1(1,0,0);
    Time T2(2,0,0);
    Bus myBus;
    myBus.setId(1);
    myBus.setType("MBus");
    myBus.setCurrentLoad(20);
    myBus.setTotalPassenger(200);
    myBus.setTDC(200);
    myBus.setN(10);
    myBus.setTBT(T1);
    myBus.setTSim(T2);
    myBus.setdirection('F');
    
    
    int utilization = myBus.BusUtilization(myBus.getTDC(), myBus.getCapacity(), myBus.getN(), myBus.getTBT(), myBus.getTsim());

    cout << "Bus Utilization: " << utilization << "%" << endl;

    return 0;
}
