#include <iostream>
using namespace std;


\

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& n) : name(n) {}
    // void makeSound() = 0;
    virtual void makeSound() = 0;
};

class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}
    void makeSound() {
        std::cout << "Cat named " << name << " says Meow!" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    void makeSound() {
        std::cout << "Dog named " << name << " says Woof!" << std::endl;
    }
};

int main() {
    Cat cat("Whiskers");
    Dog dog("Rover");
    cat.makeSound();
    dog.makeSound();
    return 0;
}