#include <iostream>
using namespace std;
#include "Station.h"
#include "Company.h"
#include <fstream>


int main(){

Station x(1,5); 
Time y (4,23,5);
Time v (9,8,6);
Passenger psngr1(1,1,2,y,v,"NP");
x.AddToFinishList(psngr1);
x.printFinishListAttributes();






// Create a text file
ofstream WriteFile("filename.txt");

// Write to the file
WriteFile << "A SP 4:19 6 2 1 Pregnant \n"
              << "A NP 4:31 7 2 1 \n "
              << "A NP 4:39 8 2 1 \n"
              << "A SP 4 : 43 9 1 2 Pregnant \n"
              << "A WP 4 : 51 10 2 1 \n";

 // Close the file
WriteFile.close();

Company cmp;
ifstream readfile("files.txt");
cmp.StartProgram(readfile);

return 0;
}