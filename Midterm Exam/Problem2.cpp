// John Liao
// CS 341 Fall 2015
// Midterm Exam - Problem #2
// main.cpp

#include <string>
#include <iostream>
using namespace std;

//#include "Node.h"
class Node {
public:
    Node () {}
    Node* putNode (Node*, string);
    string getNodeData ();
    Node* getNextPointer ();
    void setNextPointer (Node*);
    void putNextPointer (Node*);
    void setNodeData (string);
    int calcStringSum(string);
private:
    string st;
    Node* nextPtr;
};

#include <cstdlib>

Node* Node::getNextPointer (){
    return this->nextPtr;
}
void Node::putNextPointer (Node* x){
    this->nextPtr = x;
}
Node* Node::putNode (Node* x, string s) {
    
    // ---------------------- 2B ---------------------- //
    
    Node* temp = NULL;
    Node* traverse_node;
    Node* previous_node = x;
    
    // Check edge cases:
    //   (1) first node and
    //   (2) if user data is greater than head node value
    
    if (x == NULL || calcStringSum(x->getNodeData()) >= calcStringSum(s)) {
        if ((temp = new Node())) {
            temp->nextPtr = x;
            temp->st = s;
            
            return temp; // head node ptr changes!
        }
    }

    // Traverse nodes.
    // If user data val > than current node, then
    // insert new node before current node.
    // Previous node -> nextPtr connects to new node
    // New node -> nextPtr connects to current node
    
    for (traverse_node = x; traverse_node != NULL; traverse_node = traverse_node->getNextPointer()) {
        if (traverse_node != NULL) {
            if (calcStringSum(traverse_node->getNodeData()) > calcStringSum(s)) {
                if(((temp = new Node()))) {
                    temp->st = s;
                    previous_node->nextPtr = temp;
                    temp->nextPtr = traverse_node;
                    
                    return x; // keep head ptr the same
                }
            }
        }
        previous_node = traverse_node;
    }
    
    // Reached the end of the list.
    // Therefore the new node should exist at the end
    
    if(((temp = new Node()))) {
        temp->st = s;
        previous_node->setNextPointer(temp);
        temp->nextPtr = NULL;
    }
    
    return x; // keep head ptr the same
}

string Node::getNodeData() {
    return st;
}

void Node::setNextPointer(Node* ptr) {
    nextPtr = ptr;
}

void Node::setNodeData(string data) {
    st = data;
}

int Node::calcStringSum(string str) {
    int sum = 0;
    
    for (int i = 0; i < str.length(); i++){
        sum += (int) str[i];
    }
    
    return sum;
}


//#include "BagList.h"
class BagList {  //Container class
public:
    BagList ();
    bool putANode (string);
    void getList ();
    Node* findNode (string);
    void  deleteNode (string);
    bool sort();
private:
    Node* ListPointer;
};

BagList::BagList ()
{ListPointer = NULL;}
bool BagList::putANode (string udata) {
    
    bool x = false;
    Node* temp1;
    Node A;
    
    temp1 = A.putNode (ListPointer, udata);
    if (temp1 != NULL)
    {   ListPointer = temp1;
        x = true;
    }
    return x;
}
void BagList::getList() { // return value shoould be a string of concatenated variables
    Node* temp;
    for (temp = ListPointer; temp != NULL; temp = temp->getNextPointer())
        cout << " User Data " << temp->getNodeData () << endl;
}
Node* BagList::findNode (string udata){
    Node* temp;
    for (temp = ListPointer; temp != NULL && temp->getNodeData () != udata;
         temp = temp->getNextPointer());
    return temp;
}
void BagList::deleteNode (string udata) {  // suggested by Yelena Oulenova
    Node* delPtr = findNode (udata);
    if (delPtr != NULL) {
        if (ListPointer == delPtr)
            ListPointer = delPtr->getNextPointer();
        else { 	Node* previousPtr;
            Node* temp = ListPointer;
            for (previousPtr = NULL; temp != delPtr;
                 previousPtr = temp, temp = temp->getNextPointer());
            previousPtr->putNextPointer(delPtr->getNextPointer());
        }
        delete delPtr;
        delPtr = NULL; //clears any previous reference retained in this variable
        cout << "Node deleted: " << udata << endl;
    }
    else
        cout << "Node not found: " << udata << endl;
}

int main () {
    BagList A;  // declare a Container object
    string udata;
    bool cont = true;
    char sel;
    while (!cin.eof() && cont == true) {
        cout << "Enter your function: Add, Delete, Exit, Find, List: ";
        cin >> sel;
        if (!cin.eof()) {
            switch (sel) {
                case 'A': case 'a': {
                    cout << "Enter a string of characters or control-z to end ";
                    cin >> udata;
                    if (!cin.eof())
                        cont = A.putANode(udata); // put in message instead of using cont.
                    break;
                }
                case 'D': case 'd': {
                    cout << "Please Enter User Data value to delete: ";
                    cin >> udata;
                    if (!cin.eof())
                        A.deleteNode (udata);
                    break;
                }
                case 'E': case 'e': {
                    cont = false;
                    break;
                }
                case 'F': case 'f': {
                    cout << "Please Enter User Data value to find: ";
                    cin >> udata;
                    if (!cin.eof())
                        if (A.findNode(udata))
                            cout << "Node " << udata << " found" << endl;
                        else
                            cout << "Node " << udata << " not found" << endl;
                    break;
                }
                case 'L': case 'l': {
                    cout << "List of nodes" << endl;
                    A.getList();
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Invalid function entered." << endl;
                    break;
                }
            }
        }
    }
    //	system ("PAUSE");
    return 0;
}