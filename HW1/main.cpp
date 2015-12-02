//  John Liao
//  CS 341 FALL SEMESTER 2015
//  main.cpp
//  HW 1

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;


class roots {
public:
    roots() {a = b = c = 0;}
    roots(double A, double B, double C) {
        a = A; b = B; c = C;
    }
    
    void calculateDisc();
    void calculateRoots();
    bool checkRoots();
    
private:
    double a, b, c, disc;
};

bool roots::checkRoots() {
    if (disc < 0)
        return false;
    else // one or two roots
        return true;
}

void roots::calculateDisc() {
    disc = b*b - 4*a*c;
}

void roots::calculateRoots() {
    if (disc == 0) { // single root
        double root = -b/(2*a);  // get the single value
        if (root == 0) root = abs(root);    // and test for negative zero
        cout << " One real root; x = " << root;  // display the root
    }
    
    else { // show both roots
        double root1, root2;
        root1 = -b/(2*a) + sqrt (disc)/(2*a);
        root2 = -b/(2*a) - sqrt (disc)/(2*a);
        cout << " Two real roots; root1 = " << root1 << " and root2 = " << root2;
    }
}


int main () {
    double a, b, c = 0;
    cout << "Please enter your three coefficients for your quadratic equation ";
    
    cin >> a >> b >> c;
    
    if (!cin.eof() && cin.good() && a != 0) {// system keyboard tests !cin.eof() and cin.good
        // test for eof from the keyboard and good input data in that order.  The !cin.eof()
        // test has to come first to check if the user wants to bail without completing his
        // data entry. If the test cin.good is put first, the control-z or control-b input
        // will be understood as an invalid input, which is an undesirable side-effect.
        // a != 0 is an application test which rejects a value which equals zero
        // application tests always follow system tests and never precede them.
        
        roots R(a, b, c);
        
        R.calculateDisc();
        
        if (!R.checkRoots())
            cout << "No real roots";
        else
            R.calculateRoots();
    }
    else
        if (!cin.eof())  // test if user wanted or not to terminate the run.  If so, let him
                     // terminate without comment to him.
            cout << " One or more invalid inputs";
    cout << endl;
    return EXIT_SUCCESS;
}

