#include <iostream>
using namespace std;

/**
 * Destructors allow dynamic memory allocated within the class to be destroyed
 *
 * Destructor is a member function with syntax:
 *      Declaration:  ~T();
 *      Definition:   T::~T();
 * Called automatically when object goes out of scope.
 *
 * Example here has a simple Rectangle class with two dynamically allocated variables
 * Just a single default constructor is present for illustrative purposes
 */
class Rectangle {
    private:
        int *width;
        int *height;
    public:
        Rectangle(void);            /* default ctor */
        ~Rectangle(void);           /* dtor */
        int area(void) { return *width * *height; };
};

/* Constructor - default */
Rectangle::Rectangle(void) {
    cout << "In default ctor..." << endl;
    width = new int;
    height = new int;
    *width = 5;
    *height = 5;
}

/* Destructor */
Rectangle::~Rectangle(void) {
    cout << "In dtor..." << endl;
    delete width;
    delete height;
}

int main() 
{
    /* Create two rectangle objects
     * One a local object, and one a dynamically created object
     * Both will call their ctor
     */
    Rectangle rectA;
    Rectangle *rectB = new Rectangle;

    cout << "rectA.area = " << rectA.area() << endl;
    cout << "rectB.area = " << rectB->area() << endl;

    /* Once we return, rectA's dtor will be called automatically, but
     * rectB's dtor will not be called since it is a dynamic variable.
     * If we delete rectB, then it's dtor will be called
     */
    delete rectB;

    return 0;
}
