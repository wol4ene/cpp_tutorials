#include <iostream>
using namespace std;

/**
 * Sometimes there may not be a meaningful defn to give to a virtual function in the base-class.
 * 
 * In the example below, the Figure class' 'draw' method doesn't have a meaningful definition.
 * We can make it a 'pure virtual' function by ending it with "= 0;"
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
