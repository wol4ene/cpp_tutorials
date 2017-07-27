#include <iostream>
using namespace std;

/**
 * In a derived class, overloaded assignment op and copy-constructors are not inherited.
 * But, they must be invoked in the overloaded assignment op and copy-constructor of the derived
 * class.  This allows the inherited member variables of the base class to be initialized properly
 * in the derived class.
 *
 * Additionally, constructors and destructors are not inherited.
 *   Constructor in derived class must call base class constructor in init section
 *   Destructor of base class will be automatically called when derived class goes out of scope
 *
 * For the overloaded assignment op, the defn of the derived overloaded assignment op would
 * typically begin with a call to the base assignment op
 * 
 *    Derived& Derived::operator=(const Derived& rhs) {
 *        Base::operator=(rhs);    // this is the special call
 *
 * For the copy-constructor, the defn of the copy-ctor for the derived class would use the
 * copy-ctor from the base class to set the inherited member vars.
 *
 *    Derived::Derived(const Derived& obj) : Base(obj) { _rest of init_ };
 */

class Base {
    private:
        int *x;
    public:
        ~Base(void) { cout << "Base dtor..." << endl; delete x; };
        Base(void)  { cout << "Base def ctor..." << endl; x = new int; *x = 5; };
        Base(const Base& obj);
        Base& operator=(const Base& rhs);
};

class Derived : public Base {
    private:
        int *y;
    public:
        ~Derived(void) { cout << "Derived dtor..." << endl; delete y; };
        Derived(void);
        Derived(const Derived& obj);
        Derived& operator=(const Derived& rhs);
};

/* Copy-ctor for base class, nothing special here */
Base::Base(const Base& obj) {
    cout << "Base copy ctor, creating with x=" << *obj.x << endl;
    x = new int;
    *x = *obj.x;
};

/* Assignment op for base class, nothing special */
Base& Base::operator=(const Base& rhs) {
    cout << "Base overloaded assignment op, overwriting x=" << *x << " with " << *rhs.x << endl;
    if (this == &rhs) {
        return *this;
    }
    delete x;
    x = new int;
    *x = *rhs.x;
    return *this;
}

/* Def ctor for derived class - NOTE it must call base class ctor in the init section!
 * Beyond that - it's just like a regular ctor
 */
Derived::Derived(void) : Base() {
    cout << "Derived def ctor..." << endl;
    y = new int;
    *y = 8;
};

/* Copy-ctor for derived class - NOTE it must call the base class copy-ctor in the init section!
 * Beyond that - it's just a regular copy-ctor
 */
Derived::Derived(const Derived& obj) : Base(obj) {
    cout << "Derived copy ctor, creating with y=" << *obj.y << endl;
    y = new int;
    *y = *obj.y;
};

/* Assignment op for derived class - NOTE it must call base class assignment op first thing!
 * Beyond that - it's just a regular assignment op
 */
Derived& Derived::operator=(const Derived& rhs) {
    Base::operator=(rhs);
    cout << "Derived overloaded assignment op, overwriting y=" << *y << " with " << *rhs.y << endl;
    if (this == &rhs) {
        return *this;
    }
    delete y;
    y = new int;
    *y = *rhs.y;
    return *this;
};

int main() {
    cout << "***Create derived obj, will call base and then derived ctor" << endl;
    Derived foo;

    cout << "***Test the copy-ctor, will call base and then derived copy ctor" << endl;
    Derived bar(foo);

    cout << "***Test the assignment op, will call base and then derived assignment op" << endl;
    bar = foo;

    cout << "***Both objects going out of scope, first derived then base dtor will be called" << endl;
    return 0;
};


