#include <iostream>
using namespace std;
#include "Station.h"



int main(){

Station x(1,5); 
Time y (4,23,5);
Time v (9,8,6);
Passenger psngr1(1,1,2,y,v,"NP");
x.AddToFinishList(psngr1);
x.printFinishListAttributes();

return 0;
}