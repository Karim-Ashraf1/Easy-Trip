#include <iostream>
using namespace std;
#include "Company.h"

int main()
{
    Company* MyCompany = new Company;
    cout << "Enter The File Name" << endl;
    string filename;
    cin >> filename;
    // MyCompany->ReadFile(filename);
    MyCompany->Simulate(filename);
   
    return 0;
}