#include <iostream>
using namespace std;

/**
 * This is a very simple dummy example of the big-three: 
 *    destructor
 *    copy constructor
 *    overloaded assignment operator
 *
 * This tutorial only shows basic syntax and common code neede for any of the
 * members.
 *
 * For a complete example, see the 'detailed' version of this tutorial
 */
class T {
    public:
        T(void);
        ~T(void);
        T(const T& obj);
        T& operator=(const T& rhs);
};

T::T(void) {
    cout << "no arg ctor" << endl;
}

T::~T(void) {
    cout << "dtor" << endl;
}

T::T(const T& obj) {
    cout << "copy ctor" << endl;
}

T& T::operator=(const T& rhs) {
    cout << "overloaded assignment operaotr " << endl;
    if (this == &rhs) {
        return *this;
    }
    return *this;
}

int main(void) {
    return 0;
};

