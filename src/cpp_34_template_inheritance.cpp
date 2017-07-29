#include <iostream>
using namespace std;

/**
 * Inheritance of templated classes is straightforward, there are just some syntax
 * nuances to get correct.
 *
 * When inheriting, need to inherit from the Base<T>, and not just Base
 * 
 * In derived ctor, need to call base ctor in init section:  
 *     Derived<T>::Derived(void) : Base<T>() , _rest_of_init_ {};  // def ctor example
 *     Derived<T>::Derived(T val): Base<T>(val) : _rest_of_init_ {}; // one arg ctor example
 */

/**** BASE CLASS ****/
template<class T>
class A {
    private:
        T val;
    public:
        A(void);
        A(T newVal);
};

template<class T>
A<T>::A(void) : val(0) {
    cout << "A def ctor" << endl;
};

template<class T>
A<T>::A(T newVal) : val(newVal) {
    cout << "A one-arg ctor, val=" << newVal << endl;
};


/**** DERIVED CLASS ****/
template<class T>
class B : public A<T> {     /* note it derives from A<T>, and not just 'A' */
    private:
        T otherVal;
    public:
        B(void);
        B(T newVal);
};

template<class T>
B<T>::B(void) : A<T>(), otherVal(0) {    /* note the call to base class ctor uses <T> */
    cout << "B def ctor" << endl;
};

template<class T>
B<T>::B(T newVal): A<T>(newVal), otherVal(newVal) { /* note the call to base class ctor uses <T> */
    cout << "B one-arg ctor, val=" << newVal << endl;
};

int main(void) {
    cout << "create instance of derived class, will call base class ctor then derived ctor..." << endl;
    B<int> b(4);

    return 0;
};
