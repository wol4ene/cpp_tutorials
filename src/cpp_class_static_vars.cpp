#include <iostream>
using namespace std;

/**
 * Member vars of a class may have 'static' keyword applied.
 * These variables are initailzed outside of the class and shared by all objects.
 * 
 * Member funcs of a class may have 'static' keyword applied.
 * Invoked using scope-resolution operator, only have access to the static vars
 */

class Rectangle {
    private:
        static int count;   /* static member variable */
        int width;
        int height;
    public:
        Rectangle(int x, int y);
        int get_count(void) const { return count; };
        static void inc_count(void);    /* static member function */
};

/* Must initialize the static member var outside the class */
int Rectangle::count = 0;

/* In ctor, bump the count */
Rectangle::Rectangle(int x, int y) : width(x), height (y) {
    cout << "In ctor" << endl;
    count++;
}

/* Func def for static member func - notice no 'static' here */
void Rectangle::inc_count(void) {
    // width++;  /* ILLEGAL - static funcs can't access non-static member var */
    count++;  /* this is fine because count is a static var */
};

int main() 
{
    /* Create three rectangle objects */
    Rectangle rectA(8,9), rectB(3,4), rectC(6,7);

    /* All three objects will be accessing the same var, should be 3 for all of them */
    cout << "Num objects: " << rectA.get_count() << endl;
    cout << "Num objects: " << rectB.get_count() << endl;
    cout << "Num objects: " << rectC.get_count() << endl;

    /* now invoke the static member func, using scope resolution operator */
    Rectangle::inc_count();

    /* now the count should be 4 */
    cout << "Num objects: " << rectA.get_count() << endl;
    return 0;
}
