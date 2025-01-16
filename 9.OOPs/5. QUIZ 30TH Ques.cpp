#include <iostream>
using namespace std;

class student {
    int marks;  // Private member variable to store marks
public:
    student() {}  // Default constructor (no parameters)

    student(int x) {  // Parameterized constructor to initialize marks
        marks = x;
    }
};

int main() {
    // Creating an object 'sl' using the parameterized constructor with value 100
    student sl(100);

    // Creating an object 's2' using the default constructor
    // This is equivalent to student s2();
    student s2;  
    // student s2();  // Note: This is a declaration of a function, not an object creation

    // Creating an object 's3' using the parameterized constructor with value 100
    student s3 = 100;  // This is equivalent to student s3(100)  cz of above single argument ctor
    
    return 0;
}
