//
//  Node.hpp
//  CS 341 HW 5
//
//  Created by John Liao on 12/5/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp
#include <iostream>
#include <string>
#include <stdio.h>

class Node {
private:
    std::string val; // current value in collating sequence
    Node* lh; // pointer to left-hand descendant Node
    Node* rh; // pointer to right-hand descendant Node
public:
    Node () { lh = rh = NULL; val = ""; }  // Node () {}
    void putVal (std::string v) { val = v; }
    std::string getVal () { return val; }
    void putLH (Node* x) { lh = x; }
    Node* getLH () { return lh; }
    void putRH (Node* x) { rh = x; }
    Node* getRH () { return rh; }
    void write (Node* n);
};

#endif /* Node_hpp */
