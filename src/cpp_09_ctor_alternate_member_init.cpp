#include <iostream>
using namespace std;

/**
 * Constructors have mulitple ways the members can be init'ed
 * 
 * Can initialize the members within the body, as usual
 *   Ex:  Rectangle::Rectangle(int x, int y) { width = x; width = y; };
 * Can initialize using 'member initalization'
 *   Ex:  Rectangle::Rectange(int x, int y) : width(x), width(y) { <optional code> }
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

#define DEF_VAL 5

/* This is one way of initialzing members */
Rectangle::Rectangle(void) {
    cout << "In default ctor" << endl;
    width = DEF_VAL; 
    height = DEF_VAL;
};

/* Alternate form using partial 'member initialization' */
Rectangle::Rectangle(int x) : width(x) {
    cout << "In single arg ctor" << endl;
    height = DEF_VAL;
};

/* Alertate form using full 'member initialization' */
Rectangle::Rectangle(int x, int y) : width(x), height(y) {
    cout << "In two arg ctor" << endl;
};

int main() 
{
    /* Demonstrate the different initialization forms */
    Rectangle rectA;        
    Rectangle rectB(7);
    Rectangle rectC(10, 11);

    cout << "rectA.area = " << rectA.area() << endl;
    cout << "rectB.area = " << rectB.area() << endl;
    cout << "rectC.area = " << rectC.area() << endl;

    return 0;
}
