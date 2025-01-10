#include <iostream>

using namespace std;

class Shape // final   // final means -> no more subclasses
{
public:
    virtual void draw() 
    {
        cout << "Generic drawing..." << endl;
    }
};

class Circle : public Shape
{
public:
    void draw() // override // means u are just syntaxically saying are overriding base class method
    {
        cout << "Circle drawing..." << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() 
    {
        cout << "Rectangle drawing..." << endl;
    }
};

class Triangle : public Shape
{
public:
    void draw()
    {
        cout << "Triangle drawing..." << endl;
    }
};

void ShapeDrawing(Shape *s)
{
    s->draw(); // draw is polymorphic
}

int main()
{
    // Circle c;
    // Rectangle r;

    // ShapeDrawing(&c);
    // ShapeDrawing(&r);

    // Triangle *t = new Triangle();
    // ShapeDrawing(t);

   // the pointer here is used bcz it allows the option of late binding by providing more control and thus implementing polymorphism which would not be allowed in simple object creation <class_name> <object_name> like syntax 

   // now with virtual keyword it will call the draw function of the type of object stored not the type of object it is not stored
    // virtual keyword
    Shape *s = new Shape();
    s->draw();

    // UPCASTING
    Shape *s3 = new Circle();
    s3->draw(); // note: here it will draw the cricle instread of shapes generic drawring method bcz in late binding due to virtual keyword it will see oh stored the circle keyword so call the circle 's draw method 

    Circle *c = new Circle();
    c->draw();

    // DOWNCAsTing
    Shape *s2 = new Shape();   
    Circle *c2 = (Circle *)s2;
    c2->draw(); // will draw generic shape bcz it contains shape type object

  
    return 0;
}
