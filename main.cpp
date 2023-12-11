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
WriteFile << "Files can be tricky, but it is fun enough!";

// Close the file
WriteFile.close();

Company cmp;
ifstream readfile("files.txt");
cmp.StartProgram(readfile);

return 0;
}