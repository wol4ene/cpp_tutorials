#include <iostream>
using namespace std;

/**
 * The definition of an inherited member function can be changed in the defintion
 * of a derived class, so that it has a meaning in the derived class that is different
 * from that in the base class.  This is 'redefinining' and the redefined function has
 * the same number and types of parameters.
 *
 * Note this is different than overloading, where number of types of arguments are changed.
 * Redefining involves identical function signatures but different definitions.
 * Overloading involves a new function with same name but different arguments.
 * 
 * Finally, note that if one needs access to the base-class definition, it can be achieved
 * via the scope resoultion operator:
 *   <object>.<BaseClass>::<func>
 */

class Shape {
    public:
        void printMsg(void) { cout << "Base only func" << endl; };
        void toRedef(void) { cout << "Base redefine func" << endl; };
        void toOverl(void) { cout << "Base overload func" << endl; };
};

class Square : public Shape {
    public:
        void toRedef(void) { cout << "Derived redefined func" << endl; };
        void toOverl(int x) { cout << "Derived overloaded func, x=" << x << endl; };
};

int main(void) {
    /* Create object of each type */
    Shape foo1;
    Square foo2;

    /* Shape can obviously call each of its funcs */
    foo1.toRedef();
    foo1.toOverl();
    foo1.printMsg();

    /* Square can call the printMsg since it inherits it */
    foo1.printMsg();

    /* Square can call the redefined func and get Square's definition */
    foo2.toRedef();

    /* Square can also call the base class's definition using scope-resolution */
    foo2.Shape::toRedef();

    /* Square can call the overloaded func and get Square's definition */
    foo2.toOverl(5);

    /* And it can also call the base class's definition, again using scope-resolution */
    foo2.Shape::toOverl();

    return 0;
}
