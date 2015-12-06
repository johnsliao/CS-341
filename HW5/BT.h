//
//  BT.hpp
//  CS 341 HW 5
//
//  Created by John Liao on 12/5/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#ifndef BT_hpp
#define BT_hpp

#include <stdio.h>
#include <iostream>
#include "Node.h"

class BT {  // Container class - does most of the work
private:
    int count;
    Node* root;
    Node* tree;
private:
    Node* addNode (Node*, std::string);
    Node* findInsertion (Node*, std::string);
    void inOrder (Node*);
    void preOrder (Node*);
    void postOrder (Node*);
    void locate (Node*, std::string);
    void treePrint(Node*, int);
public:
    BT ();
    void addRootNode (std::string);
    void inOrderTraverse ();
    void preOrderTraverse ();
    void postOrderTraverse ();
    int  getCount () { return count; }
    void locateRoot (std::string);
    void treePrintWrapper();
};

#endif /* BT_h */
