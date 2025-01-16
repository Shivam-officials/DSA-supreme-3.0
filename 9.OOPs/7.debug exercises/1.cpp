#include <iostream>
using namespace std;

class Parent {
public:
    Parent(int x) : value(x) {}
    void display() { cout << "Parent: " << value << endl; }
private:
    int value;
};

class Child : public Parent {
public:
//     Child(int y) : value(y) {}
//     void display() { cout << "Child: " << value << endl; }
// private:
//     int value;

Child(int y) : Parent(y) {} // Call the base class constructor
    // No need to redefine display() here
};

int main() {
    Child child(10);
    child.display();
    return 0;
}