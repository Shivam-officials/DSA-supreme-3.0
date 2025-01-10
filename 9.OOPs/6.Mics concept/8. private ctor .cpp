#include <iostream>
using namespace std;

// Note: Friend classes and functions can access private members of a class
//! bt avoid using friend keyword bcz its not better design .. bt u  should know it for interview purposes

class Box {
private:
  int width; // Private member to store the box's width

  // Private constructor: Only friend classes/functions can create Box objects
  Box(int _w) : width(_w) {}

public:
  // Getter for width
  int getLength() const { return width; }

  // Setter for width
  void setWidht(int _w) { width = _w; }

  // Declare BoxFactory as a friend class (can access private members)
  friend class BoxFactory;

  // Declare getBoxAuto as a friend function (can create Box objects directly)
  friend Box getBoxAuto(int _w);

  // Declare printBoxWidth as a friend function (can access private members)
  friend void printBoxWidth(const Box &b);
};

class BoxFactory {
  int count = 0; // Tracks the number of Box objects created

public:
  // Creates and returns a Box object, increments count
  Box getBox(int _w) {
    count++;
    return Box(_w);
  }
};

// Friend function to create a Box object directly
Box getBoxAuto(int _w) {
  return Box(_w);
}

// Friend function to print the width of a Box
void printBoxWidth(const Box &b) {
  cout << "The box width is: " << b.width << endl;
}

int main(int argc, char const *argv[]) {
  // Box bx(3); // Direct creation is not allowed due to the private constructor

  BoxFactory bFact; // Factory ensures controlled creation of Box objects

  // Create a Box object using the factory
  Box bx = bFact.getBox(5);

  // Create a Box object using the friend function
  Box bx2 = getBoxAuto(55);

  // Print the width of Box objects
  printBoxWidth(bx);
  cout << "Second box width: " << bx2.getLength() << endl;

  return 0;
}
