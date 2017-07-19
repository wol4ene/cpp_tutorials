#include <iostream>
using namespace std;

/**
 * Member variables that are private in a base class are not directly accessible outside
 * the implementation of the base class, not even in a member function definition for
 * a derived class!
 * 
 * To access them indirectly, we can use accessor/mutator functions defined in the base class,
 * or instead, use the 'protected' qualifier. The 'protected' qualifier allows a derived-class
 * function to access the base-class member variable by name.
 */

class Base {
    private:
        int x;                          
    protected:
        int y;
    public:
        Base(void) : x(5), y(7) { };
        void printVar(void) const;
};

class Derived : public Base {
    public:
        Derived(void) : Base() { };
        void printVar(void) const;
};

void Base::printVar(void) const {
    cout << "Base x: " << x << endl;
    cout << "Base y: " << y << endl;
};

void Derived::printVar(void) const {
    /* ILLEGAL. 'x' is private in base class, cannot access by name in derived class */
    //cout << "Derived x: " << x << endl; 
                                         
    /* LEGAL. 'y' is protected in base class, can access by name in derived class  */
    cout << "Derived y: " << y << endl; 
}

int main(void) {
    /* Create a derived object */
    Derived foo;
    
    foo.printVar();

    return 0;
}
