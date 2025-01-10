#include <iostream>
using namespace std;

class Abc {
   mutable int x; // `mutable` allows changes in const member functions but should only be used for debugging.
    int *y;
    const int z;

public:
    // old way constructor
    // Abc(int _x,int _y, int _z = 0){
    // x = _x;
    // y = new int(_y);
    // z = _z; // will not be able to initialise z if we make it const  ek bar bhi ni hoga ye shru wala bhi
    // };

    //* Constructor using initializer list
    // Note: Using the normal constructor method without an initializer list cannot initialize const variables like `z`.

    Abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z) {
        // z can only be initialized here (in the initializer list).
    }

    void setX(int _x) {
        x = _x;
    }

    void getX() const { // const ensures this function cannot modify any member variables.
        cout << x << endl;
        // x = 4; // Not allowed due to const, unless x is declared mutable.
    }

    void setY(int _y) {
        *y = _y;
    }

    void getY() const { // const ensures this function cannot modify any member variables.
        cout << *y << endl;
    }

    void setZ(int _z) {
        // z = _z; // Not allowed because z is declared const.
    }

    void getZ() const {
        cout << z << endl;
    }
};

void printAbc(const Abc &b) {
    b.getX();
    b.getY();
    b.getZ(); // Only const member functions can be called on const objects.
}

int main(int argc, char const *argv[]) {
    Abc a(1, 2, 3);

    // Access and modify x
    a.getX();
    a.setX(11);
    a.getX();

    // Access and modify y
    a.getY();
    a.setY(22);
    a.getY();

    cout << "All values now:\n";
    printAbc(a);

    return 0;
}

