#include <iostream>
using namespace std;

/**
 * Virtual functions are a corner-stone of polymorphism and allow {late/dynamic/run-time} binding
 *
 * They tell the compiler "I do not yet know how this func will be implemented. Wait until
 *                         it is used in the program and get the implementation from the object".
 *
 * If a func is virtual and a new definition of the func is given in a dervied class, then
 * for any object of the derived class, the object will always use the defn of the virt func
 * that was given in the derived class, even if the virt func is used indirectly by being
 * invoked in the defn of an inherited func.
 */

/**
 * Base figure class - it has a generic showFigure method which simply calls the virtual
 * draw method. Note that 'draw' is prefaced with 'virtual'.
 * 
 * It will be up to the derived classes to provide unique defns for draw.
 * 
 * If 'virtual' is not present here, this example would simply print "Base draw" twice.
 * To FORCE derived classes to provide a defn, see tutorial on pure-virtual func
 */
class Figure {
    public:
        void showFigure(void) { draw(); };
        virtual void draw(void) { cout << "Base draw" << endl; };
};

class Square : public Figure {
    public:
        virtual void draw(void);  /* 'virtual' not strictly needed here */
};

class Triangle : public Figure {
    public:
        virtual void draw(void);  /* 'virtual' not strictly needed here */
};

void Square::draw(void) {
    cout << "---" << endl;
    cout << "| |" << endl;
    cout << "---" << endl;
};

void Triangle::draw(void) {
    cout << " ^" << endl;
    cout << "/ \\" << endl;
    cout << "---" << endl;
};

int main(void) {
    Triangle f1;
    Square f2;

    cout << "Drawing a triangle..." << endl;
    f1.showFigure();
    cout << "Drawing a square..." << endl;
    f2.showFigure();

    return 0;
};
