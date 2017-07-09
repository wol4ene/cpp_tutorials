#include <iostream>
using namespace std;

/**
 * Operators such as '+', '-', or '==' can be overloaded within a class
 * or outside of the class.  This example shows how to do it inside of a class.
 * When defined as members of the class, they have access to private members, unlike
 * overloaded operators defined outside the class
 *
 * There is only one parameter, not two.  The calling object serves as the first parameter
 *  Money cost(1,50), tax(0,15), total;
 *  total = cost + tax;
 *  Here - cost is the calling object and tax is the single argument to the '+'
 * 
 * Note - suggested to always add 'const' to end of operator decl/defn
 *  
 * Syntax for overloading inside a class
 *   [const] <return> operator<op>([const] T& t1) const;
 * For example, to overload the '+' operator
 *    const T operator+(const T& t1) const;    // note the const at the end
 * For example, to overload the '==' operator
 *    bool operator==(const T&) const;          // note the const at the end
 */

class Acct {
    private:
        int dollars;
        int cents;
    public:
        Acct(int x, int y) : dollars(x), cents(y) { };
        Acct(void) : dollars(0), cents(0) { };
        int get_dollars(void) const { return dollars; };
        int get_cents(void) const { return cents; };
        const Acct operator+(const Acct& a1) const;
        bool operator==(const Acct& a1) const;
};

/**
 * Overloaded '+' operator.  Simply adds two Acct objects together.
 * Note this is a dumb function and doesn't adjust dollars once cents goes above 100,
 * but is just used for illustrative purposes
 */
const Acct Acct::operator+(const Acct& a1) const
{
   int sumDollars = dollars + a1.get_dollars();
   int sumCents = cents + a1.get_cents();

   return Acct(sumDollars, sumCents);
}

/** 
 * Overloaded '==' operator.  Simply tests if two Acct objects are equivalent
 */
bool Acct::operator==(const Acct& a1) const 
{
    return ( (cents == a1.get_cents()) &&
             (dollars == a1.get_dollars()));
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
