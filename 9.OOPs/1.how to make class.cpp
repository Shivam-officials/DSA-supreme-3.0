#include <iostream>
#include <string>
using namespace std;


class Student{
    private:
        // Attributes
        int id;
        int age;
        string name;
        int nos;
        int * pets;
        string gf;



    public:

        // ctor :Default ctor
        Student(){
        cout  <<"student defualt ctor is called"<<endl;
        }

        //ctor: parametarised ctor
        Student(int id,int age,string name, int nos,int  pets,string gf){
            cout << "Student parametreised ctor called for "<<name<<endl;
            this->id = id;
            this->age = age;
            this->name = name;
            this->nos = nos;
            this->pets = new int(pets);
            this-> gf = gf;
        }

        //copy ctor
        Student(const Student &srcObj){
            cout << "copy constructor is called from the copy of "<<srcObj.name<<endl;
            this->age = srcObj.age;
            this->id = srcObj.id;
            this->name = srcObj.name;
            this->nos = srcObj.nos;
            
        }

        int getId(){
           return id;
        }

        void setNos(int nos){
            this->nos = nos;
        }
         
        int getNos(){
            return nos;
        }

        //behaviour /method /funcitons
        void study(){
            cout << this->name<<" studing "<<endl;
        }

        void sleep(){
            cout << this->name<<" sleeping "<<endl;
        }

        void bunk(){
            cout << this->name<<" bunking "<<endl;
            gf_chatting();
        }

       
       
       //dtor
        ~Student(){
            cout << "Student default dtor called for "<<this->name<<endl;
            delete pets;
            // cout << "deleted the pets\n";
        }
    private:
    void gf_chatting(){
        cout << "chatting with girlfriend "<<gf<<endl;
    }

};


int main(int argc, char const *argv[])
{
     
     
    
    Student A (21,23,"white",7,4,"V");
    Student B (1,24,"black",7,8,"A");
    Student C (1,23,"ritesh",7,0,"No");
    A.sleep();
    B.bunk();
    C.study(); 
   cout <<  B.getId()<<" "<< A.getNos() <<endl;
    A.setNos(9); 
    cout << A.getNos()<<endl;
    // Student D =  C;
    // cout << D.name<<" "<<C.name<<endl;

    Student *E =  new Student(33,24,"sandesh",6,4,"D");
    delete E;
    return 0;
}
