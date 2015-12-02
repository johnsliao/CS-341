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

void FindMiddle(int x, int y, int level, int nr,
                int round)
{ int mid;
    if (abs(x-y)<2)
    { if (x==1)
        cout << level << " " << setw(2) << x << endl;
        if (y==nr)
            cout << level << " " << setw(2) << y << endl;
        return;
    }
    if ((y+x)%2)
    { mid=(x+y+round)/2;
        cout << level << " " << setw(2) << mid << endl;
    }
    else
    { mid = (x+y)/2;
        cout << level << " " << setw(2) << mid << endl;
    }
    FindMiddle(x,mid,(level+1),nr,-1); // round down left
    FindMiddle(mid,y,(level+1),nr,1);  // round up right
    return;
}