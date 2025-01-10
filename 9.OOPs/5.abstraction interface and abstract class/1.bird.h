#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>
using namespace std;

//interface or interface both are same in cpp unlike java .. 
//abstract class  -> atleast one virtual function should be in the class
class Bird{
    //interface
    public:
    virtual void fly() = 0; 
    virtual void eat() = 0;
};


//implementation
class Sparrow : public Bird{
 private:
    void fly(){
        cout << "sparrow is flying .. \n";
    }
     void eat(){
    cout << "sparrow is eating..\n";
     }
};


class Eagle:public Bird{
    private:
        void fly() override{
            cout << "eagle is flying faster..\n";
        }

        void eat() override{
            cout << "eagle is eating faster..\n";
        }
};

#endif
