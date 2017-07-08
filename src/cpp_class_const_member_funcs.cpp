#include <iostream>
using namespace std;

/**
 * Member funcs of a class may have 'const' applied after the function name,
 * which tells the compiler the function will not modify the calling object
 * 
 * In the class def, func will have 'const' after the normal func decl
 *     <return> <funcName>(<args>) const;
 *
 * In the definition, assuming scope-resolution used, will look like:
 *     <return> <ClassName>::<funcName>(<args>) const {<function definition>};
 */

class Rectangle {
    private:
        int width;
        int height;
    public:
        Rectangle(int x, int y) : width(x), height(y) { cout << "In ctor " << endl; };

        void func1(void);           /* no 'const' appears, may modify calling object */
        void func2(void) const;     /* const appears, cannot modify calling ojbect */
};

/* Regular func, no const */
void Rectangle::func1(void) {
    width = 5;      /* legal */
};

/* New const function, notice that const appears before opening  bracket */
void Rectangle::func2(void) const {
    width = 5;                           /* ILLEGAL - compiler warning! */
    cout << "width: " << width << endl;  /* legal, not modifying */
};

int main() 
{
    /* Create two rectangle objects */
    Rectangle rect(8,9);

    rect.func1();
    rect.func2();

    return 0;
}
