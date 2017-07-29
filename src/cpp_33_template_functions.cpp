#include <iostream>
using namespace std;

/**
 * Function templates allow arguments of any type to be passed into a func
 * In the 'swap_int' and 'swap_char' functions below, the algorithm is the same,
 * but the only real difference is the type of variables.
 *
 * We can abstract that with templates.  A function decl AND defn that uses templates begins with:
 *     template<class T>
 *
 * NOTE - 'class' doesn't mean the usual 'class' in C++.
 */

/* int-specific version of swap */
void swap_int(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
};

/* char-specific version of swap */
void swap_char(char &x, char &y) {
    char tmp = x;
    x = y;
    y = tmp;
};

/* Generic version of swap using templates! */
template<class T>               // Function decl, need the template prefix
void swapGeneric(T &x, T &y);

template<class T>               // Function defn, need the template prefix
void swapGeneric(T &x, T &y) {
    T tmp = x;
    x = y;
    y = tmp;
};

int main(void) {
    int i1 = 5, i2 = 8;
    char c1 = 'a', c2 = 'c';

    cout << "Before swap:  i1=" << i1 << " i2=" << i2 << endl;
    cout << "Before swap:  c1=" << c1 << " c2=" << c2 << endl;

    cout << "Swapping..." << endl;
    swapGeneric(i1, i2);
    swapGeneric(c1, c2);

    cout << "After swap:  i1=" << i1 << " i2=" << i2 << endl;
    cout << "After swap:  c1=" << c1 << " c2=" << c2 << endl;

    return 0;
}
