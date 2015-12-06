#include <iostream>
#include <iomanip>  // for setw
#include <cstdlib>
#include <string>

#include "Node.h"
using namespace std;

void Node::write (Node* n) { // Diagnostic to display a node of a Binary Tree
    cout << "Value " << val << " in Node at " << (int)(size_t)n;
    
    
    
    if (lh!=nullptr)
        cout << "\t Its LH child "  << lh->getVal();
    else
        cout << "\t Its LH child 0";
    
    if (rh!=nullptr)
        cout << "\t Its RH child "<< rh->getVal() << endl;
    else
        cout << "\t Its RH child 0";
}