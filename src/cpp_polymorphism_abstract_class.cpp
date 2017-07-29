#include <iostream>
using namespace std;

/**
 * A class with one ore more pure virtual functions is an Abstract Class. 
 *
 * It can only be used to derive other classes, no objects of the base class can be instantiated
 * 
 * Note - a derived class of an abstract class will also be abstract if we do not provided defns
 *        for all inherited virtual methods.
 */

/**
 * Base figure class - it has a generic showFigure method which simply calls the virtual
 * draw method. Note that 'draw' is prefaced with 'virtual'.
 * 
 * It will be up to the derived classes to provide unique defns for draw.
 */
class Figure {
    public:
        void showFigure(void) { draw(); };
        virtual void draw(void) = 0;   /* this "= 0;" makes this a pure virt func */
};

class Square : public Figure {
    public:
        virtual void draw(void);  /* 'virtual' not strictly needed here */
};

void Square::draw(void) {
    cout << "---" << endl;
    cout << "| |" << endl;
    cout << "---" << endl;
};

int main(void) {

    cout << "Drawing a square..." << endl;
    Square f1;
    f1.showFigure();

    // Figure f2;  /* ILLEGAL - cannot instantiate an abstract class! */
    return 0;
};
