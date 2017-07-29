#include <iostream>
using namespace std;

/**
 * This tutorial simply provides an alternative way of representing virtual functions.
 * In the previous tutorial, the base class had a func which would call the virtual func,
 * but we can call the virt func directly using a pointer to the base class
 */

class Figure {
    public:
        virtual void draw(void) { cout << "Base draw" << endl; };
};

class Square : public Figure {
    public:
        virtual void draw(void) { cout << "Square draw" << endl; }; 
};

class Triangle : public Figure {
    public:
        virtual void draw(void) { cout << "Triangle draw" << endl; };
};

int main(void) {
    Figure *fp;   // base class ptr, will assign to each of the derived classes
                  // and call their draw funcs, which will use late-binding

    Square sq;
    Triangle tri;

    cout << "Using polymorphism to print Square's draw func..." << endl;
    fp = &sq;
    fp->draw();

    cout << "Using polymorphism to print Triangle's draw func..." << endl;
    fp = &tri;
    fp->draw();

    return 0;
};
