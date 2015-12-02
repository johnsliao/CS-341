// John Liao
// CS 341 - Fall 2015
// HW #5
// main.cpp

// some change to main

#include "findmiddle.h"

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    string name;
    fstream inFile("names.txt");
    string namesArr[14];

    for (int x=0; inFile >> name; x++) {
        namesArr[x] = name;
        cout << namesArr[x] << " has been stored in the unsorted names array" << endl;
    }
    
    
    
    /*int nr, level=0;
    cout << "Enter integer number of elements: ";
    if (cin >> nr)
        if (nr>2)
            FindMiddle(1,nr,(level+1),nr,1);*/
    return 0;
}