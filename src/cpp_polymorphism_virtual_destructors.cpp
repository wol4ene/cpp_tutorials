#include <iostream>
using namespace std;

/**
 * Destructors should always be virtual.
 *
 * If polymorphism is being used, then if dtors are not virtual, the derived
 * dtor will not be called, and thus memory will be leaked
 */

class A {
    public:
        A(void) { cout << "A ctor - may alloc some memory" << endl; };
        ~A(void) { cout << "A dtor" << endl; };
};

class B : public A {
    public:
        B(void) : A() { cout << "B ctor - may alloc some memory" << endl; };
        ~B(void) { cout << "B dtor " << endl; };
};

class C {
    public:
        C(void) { cout << "C ctor - may alloc some memory" << endl; };
        virtual ~C(void) { cout << "C dtor" << endl; };
};

class D : public C {
    public:
        D(void) : C() { cout << "D ctor - may alloc some memory" << endl; };
        virtual ~D(void) { cout << "D dtor" << endl; };
};

int main() {

    cout << "Without virtual dtors create base ptr A pointing to derived object B..." << endl;
    A *ap = new B;

    cout << "Now - deleting object only calls the base-class A dtor!" << endl;
    cout << "We've lost any memory that derived-class B may have alloced..." << endl;
    delete ap;

    cout << "\nNow let's use polymorphism with the dtor being virtual..." << endl;
    cout << "Create base ptr class C pointing to derived class D..." << endl;
    C *cp = new D;

    cout << "Now - deleting object calls derived class D dtor then base class C dtor!" << endl;
    cout << "This will free up any memory possibly allocated..." << endl;
    delete cp;


    return 0;
};
