#include "iostream"
using namespace std;

// base class
class Shape {
    // access modifiers => public, protected, private
protected:
    double dimension;
public:
    // constructor
//     Shape(double dimension) {
//         this->dimension = dimension;
//         cout << "initialized" << endl;
//     }
    Shape(double d):dimension(d) {
      cout << "initialized" << endl;
    }
    // pure virtual functions have to be overridden as they have no body
    virtual double area() = 0;  // pure virtual  function "abstract"
    virtual void display() = 0;

    // destructor
    // virtual function can be overridden
    virtual ~Shape() {
        cout << "shape deleted" << endl;
    };
};

// child class circle, inherits from shape
class Circle : public Shape {
public:
    Circle(double radius) : Shape(radius) {} // child's constructor

    double area() override {  // overriding
        return 3.14 * dimension * dimension;
    }

    void display() override {
        cout << "Circle with radius: " << dimension
                  << ", Area: " << area() << endl;
    }
};

// another child class
class Square : public Shape {
public:
    Square(double side) : Shape(side) {}

    double area() override {
        return dimension * dimension;
    }

    void display() override {
        cout << "Square with side: " << dimension
                  << ", Area: " << area() << endl;
    }
};

int main() {
    Shape * shapes[2];

    shapes[0] = new Circle(5);
    shapes[1] = new Square(4);

    for (int i = 0; i < 2; i++) {
        // call display function
//         (*shapes[i]).display();
        shapes[i]->display();

        // automatically calls the destructor
        delete shapes[i];

    }


    return 0;
}
