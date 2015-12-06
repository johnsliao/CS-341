// John Liao
// CS 341 - Fall 2015
// HW #5
// main.cpp

// some change to main

#include "findmiddle.h"
#include "BT.h"
#include "Node.h"

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int getASCII(string str) {
    int sum = 0;
    
    for (int x=0; x<str.size(); x++)
        sum+=(int)str[x];
    
    return sum;
}

void sortArray(string * _namesArr, int _numNames) {
    // using selection sort to sort array
    int imin = 0;
    int i,j;
    
    for (i=0; i<_numNames; i++) {
        // imin moves along with i
        // i is the index (to the left is sorted, right is unsorted)
        
        imin = i;
        
        for (j=i; j<_numNames; j++) { // look past i to find the "true" min
            if (getASCII(_namesArr[j]) < getASCII(_namesArr[imin]))
                imin = j;
        }
        
        
        if (imin != i) { // if imin != i, new min found
            string temp = _namesArr[i];
            
            _namesArr[i] = _namesArr[imin];
            _namesArr[imin] = temp;
        }
    }
}

int main()
{
    string name;
    fstream inFile("names.txt");
    string namesArr[50]; // assume # names < 50
    
    int numNames = 0;
    int test[14];
    int nr=14, level=0;

    for (; inFile >> name; numNames++) { // read in names from txt file
        namesArr[numNames] = name;
    }
    
    cout << "UNSORTED LIST" << endl;
    for (int x=0; x<numNames; x++) {
        cout << namesArr[x] << endl;
    }

    sortArray(namesArr, numNames);
    
    cout << "SORTED LIST" << endl;
    for (int x=0; x<numNames; x++) {
        cout << namesArr[x] << endl;
    }

    FindMiddle(test, 1,nr,(level+1),nr,1);

    for (int y =0 ; y<numNames; y++)
        cout << test[y] << endl;
    
    BT TREE;
    for (int y =0 ; y<numNames; y++)
        TREE.addRootNode (namesArr[test[y]]);

    TREE.inOrderTraverse ();
    
    return 0;
}