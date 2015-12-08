//
//  findmiddle.cpp
//  CS 341 HW 5
//
//  Created by John Liao on 11/29/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#include "findmiddle.h"

using namespace std;

void FindMiddle(int * _test, int x, int y, int level, int nr, int round) {
    int mid;

    if (abs(x-y)<2) {
        if (x==1) {
            while(*_test != 0) // add value to end of the list...
                _test++;
            *_test = x; // -1 since 0-based array
        }
        if (y==nr) {
            while(*_test != 0) // add value to end of the list...
                _test++;
            *_test = y; // -1 since 0-based array
        }
        
        return;
    }
    if ((y+x)%2) {
        mid=(x+y+round)/2;
        while(*_test != 0) // add value to end of the list...
            _test++;
        *_test = mid; // -1 since 0-based array
    }
    else {
        mid = (x+y)/2;
        while(*_test != 0) // add value to end of the list...
            _test++;
        *_test = mid; // -1 since 0-based array
    }
    
    FindMiddle(_test, x,mid,(level+1),nr,-1); // round down left
    FindMiddle(_test, mid,y,(level+1),nr,1);  // round up right
    
    return;
}