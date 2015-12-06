#include <iostream>
#include <iomanip>  // for setw
#include <cstdlib>
#include <string>
#include "BT.h"

using namespace std;

BT::BT () { root = tree = NULL; count = 0; }    // BT::BT () {}
void BT::addRootNode (string v)
{ if (root == NULL)
{root = tree = addNode (tree, v);
    //	 cout << "ptr to root " << root << endl;
}
else
{ tree = root;
		  tree = findInsertion (tree, v);
} }
void BT::locateRoot (string v) {
    if ( root == NULL )
        cout << "Tree is empty" << endl;
    else
        locate ( root, v );
}
void BT::locate (Node* y, string v) {  // Bug mentioned by Dan Glade
    string x;
    x = y -> getVal ();
    if ( v == x )
    { cout << "Value " << v << " is in Node at address " << (int)(size_t)y << endl;
        // cout << "Its LH reference is "  << (int)(y -> getLH()) << endl << "Its RH reference is " << (int)(y -> getRH()) << endl;
    }
    else if ( v < x )
        if ( y -> getLH() != NULL )
            locate (y-> getLH(), v);
        else
            cout << "Value not in tree" << endl;
        else // if ( v > x )
            if ( y -> getRH() != NULL )
                locate ( y-> getRH(), v );
            else
                cout << "Value not in tree" << endl;
}
Node* BT::findInsertion (Node* tree, string v)
{ string x;
    x = tree -> getVal();
    cout << count << " compare " << v << " and " << x << endl;
    if ( v <= x )
        if( tree -> getLH () !=NULL )
        { tree = findInsertion (tree -> getLH(), v);
            return tree;		// *** from Paul Pollack 11/13/13 ***new addition to prevent
            // a new node from being added twice
        }
        else
        { Node* temp = NULL;
            temp = addNode (temp, v);
            tree ->putLH(temp); }
        else // if ( v > x )
            if (tree -> getRH () !=NULL )
            { tree = findInsertion (tree -> getRH(), v);
                return tree;		// *** from Paul Pollack 11/13/13 ***new addition to prevent
                // a new node from being added twice
            }
            else
            { Node* temp = NULL;
                temp = addNode (temp, v);
                tree ->putRH(temp); }
    return tree; }
Node* BT::addNode (Node* x, string v)
{ if (x = new Node)
{ x->putVal (v);
		  ++count;
    //  cout << count << " " << x << " " << x->getVal () << endl;
		  x->putLH(NULL);
		  x->putRH(NULL); }
    return x; }
void BT::inOrderTraverse ()
{ //tree = root;
    cout << endl;
    inOrder (root); }
void BT::inOrder (Node* n)
{ if (n != NULL) {
    inOrder (n->getLH());
    n->write (n);
    cout << endl;
    inOrder (n->getRH());
}
    return;
}
void BT::preOrderTraverse ()
{ //tree = root;
    cout << endl;
    preOrder (root); }
void BT::preOrder (Node* n)
{ if (n == NULL) return;
    n->write (n);
    cout << endl;
    preOrder (n->getLH());
    preOrder (n->getRH()); }
void BT::postOrderTraverse ()
{ //tree = root;
    cout << endl;
    postOrder (root); }
void BT::postOrder (Node* n)
{ if (n != NULL) //return;
{ postOrder (n->getLH());
		  postOrder (n->getRH());
		  n->write (n);
		  cout << endl;
}
}
void BT::treePrintWrapper() {
    treePrint(root, 0);
}

void BT::treePrint(Node* ref, int depth) {
    // from Main & Savitch page 506
    cout << setw(4*depth) << ""; // indentation
    if (ref == NULL) {
        // reached a NULL reference in an interior node
        cout << "[NULL]" << endl;
    } else if (ref->getLH() == NULL && ref->getRH() == NULL) {
        // a leaf
        cout << "Value " << ref->getVal() << " at Ref " << (int)(size_t) root;
        cout << " [leaf]" << endl;
    } else {
        // a nonleaf - interior node
        cout << "Value " << ref->getVal() << " at Ref " << (int)(size_t) ref << endl;
        cout << "LH" << depth+1;
        treePrint(ref->getLH(), depth + 1);
        cout << "RH" << depth+1;
        treePrint(ref->getRH(), depth + 1);
    }
}