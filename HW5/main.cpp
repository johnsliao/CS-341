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

void printArr(string * _arr, int size) {
    for (int x=0; x<size; x++)
        cout << _arr[x] << " ";
    
    cout << endl;
}

int main()
{
    BT TREE;

    const int numNames = 14; // ** Must hard code numNames to 14 because illegal to assign variable int size to array, i.e. int arr[val] if val = 14. **
    
    string name;
    string namesArr[numNames];
    
    fstream inFile("names.txt"); // I chose to read in names via txt file to make testing easier

    int balancedTree [numNames];
    int nr=numNames, level=0;
    
    for (int q=0; inFile >> name; q++) // read in names from txt file
        namesArr[q] = name;
    
    cout << "\n\n---------------------------------<<UNSORTED LIST>>---------------------------------\n" << endl;
    printArr(namesArr, numNames);
    
    sortArray(namesArr, numNames);
    
    cout << "\n\n---------------------------------<<SORTED LIST>>---------------------------------\n" << endl;
    printArr(namesArr, numNames);

    FindMiddle(balancedTree, 1,nr,(level+1),nr,1); // Use the count of array elements and the findMiddle… algorithm to rearrange the sorted array into an array which contains the middle element in the first position, etc...

    for (int y = 0 ; y<numNames; y++) // account for 0 based array. FindMiddle.cpp is for 1 based array
        balancedTree[y]--;

    for (int z = 0 ; z<numNames; z++) // add list elements to BT in the correct order
        TREE.addRootNode (namesArr[balancedTree[z]]);
    
    cout << "\n\n---------------------------------<<TREE PRINT OUT>>---------------------------------" << endl;
    TREE.inOrderTraverse (); // print tree
    
    return 0;
}