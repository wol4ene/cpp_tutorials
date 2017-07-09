#include <iostream>
using namespace std;

/**
 * Operators such as '+', '-', or '==' can be overloaded within a class
 * or outside of the class.  This example shows how to do it outside of a class,
 * and in this case, the functions will not have access to private members of the class
 * and as such must use accessor functions.
 * 
 * Syntax for overloading outside a class:
 *   [const] <return> operator<op>([const] T& t1, [const] T& t2);
 * For example, to overload the '+' operator
 *    const T operator+(const T& t1, const T& t2);
 * For example, to overload the '==' operator
 *    bool operator==(const T& t1, const T& t2);
 */

class Acct {
    private:
        int dollars;
        int cents;
    public:
        Acct(int x, int y) : dollars(x), cents(y) { };
        Acct(void) : dollars(0), cents(0) { };
        int get_dollars(void) const { return dollars; };    /* note the const */
        int get_cents(void) const { return cents; };        /* note the const */
};

/**
 * Overloaded '+' operator.  Simply adds two Acct objects together.
 * Note this is a dumb function and doesn't adjust dollars once cents goes above 100,
 * but is just used for illustrative purposes
 */
const Acct operator+(const Acct& a1, const Acct& a2)
{
   int sumDollars = a1.get_dollars() + a2.get_dollars();
   int sumCents = a1.get_cents() + a2.get_cents();

   return Acct(sumDollars, sumCents);
}

/** 
 * Overloaded '==' operator.  Simply tests if two Acct objects are equivalent
 */
bool operator==(const Acct& a1, const Acct& a2)
{
    return ( (a1.get_cents() == a2.get_cents()) &&
             (a1.get_dollars() == a2.get_dollars()));
}

int main() 
{
    /* Create two Acct objects */
    Acct acct1(24,7), acct2(5,9);

    /* sum them up to a new object should be 29 dollars, 16 cents  */
    Acct acct3 = acct1 + acct2;

    cout << "Acct3.dollars = " << acct3.get_dollars() << endl;
    cout << "Acct3.cents = " << acct3.get_cents() << endl;

    /* Create a 4th and 5th object to test the overloaded '==' operator */
    Acct acct4(1,1), acct5(29,16);

    if (acct4 == acct3) {
        cout << "whoops, wrong math" << endl;
    }
    if (acct5 == acct3) {
        cout << "acct5 == acct3" << endl;
    }

    return 0;
}
