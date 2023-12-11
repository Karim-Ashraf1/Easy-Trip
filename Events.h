#include<iostream>
using namespace std;

class Events{
private:
    
public:
    virtual void Execute(int FileArray[]) =0 {
        //Pure virtual function to be executed by inherited classes
    }
};



