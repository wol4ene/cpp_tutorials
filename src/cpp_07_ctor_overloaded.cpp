#include <iostream>
using namespace std;

/**
 * Constructors can be overloaded to handle different scenarios.
 * Also, like regular member functions, can be defined outside class
 * with scope-resolution operator.
 * 
 * Constructor with no arguments is the default constructor
 */

class Rectangle {
    private:
        int width;
        int height;
    public:
        Rectangle(void);         /* default ctor */
        Rectangle(int x);        /* ctor with one arg */
        Rectangle(int x, int y); /* ctor with two args */
        int area(void) { return width * height; };
};

#define DEF_VAL 5;

Rectangle::Rectangle(void) {
    cout << "In default ctor" << endl;
    width = DEF_VAL; 
    height = DEF_VAL;
};

Rectangle::Rectangle(int x) {
    cout << "In single arg ctor" << endl;
    width = x;
    height = DEF_VAL;
};

Rectangle::Rectangle(int x, int y) {
    cout << "In two arg ctor" << endl;
    width = x;
    height = y;
};

int main() 
{
    // Rectangle rect();   // WRONG - doesn't create an object with default ctor
                           //         this creates a new func.  need to leave off
                           //         parens to get an object with default ctor

    // Create 3 objects, each calling different constructors */
    Rectangle rectA;       /* default ctor, area will be the defaults, 5*5 = 25 */
    Rectangle rectB(8);    /* one arg ctor, area will be 8 * 5 = 40 */
    Rectangle rectC(6,9);  /* two arg ctor, area will be 6 * 9 = 54 */

    cout << "rectA.area = " << rectA.area() << endl;
    cout << "rectB.area = " << rectB.area() << endl;
    cout << "rectC.area = " << rectC.area() << endl;

    return 0;
}
