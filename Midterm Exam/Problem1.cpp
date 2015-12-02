// John Liao
// CS 341 Fall 2015
// Midterm Exam - Problem #1
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
    Node* temp;
    
    if ((temp = new Node())) {
        temp->nextPtr = x;
        temp->st = s;
    }
    
    return temp;
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

//#include "BagList.h"
class BagList {  //Container class
public:
    BagList ();
    bool putANode (string);
    void getList ();
    Node* findNode (string);
    void  deleteNode (string);
    bool sort();
    int calcStringSum(string);
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

int BagList::calcStringSum(string str) {
    int sum = 0;
    
    for (int i = 0; i < str.length(); i++){
        sum += (int) str[i];
    }
    
    return sum;
}

bool BagList::sort() {
    // ------------------------------ 1B.i ------------------------------ //
    // This entry will dump the original linked list to a dynamic array,
    // which is then sorted in ascending order.
    
    int length = 0;
    int c = 0;
    
    Node* temp_node;
    
    bool done = true;
    
    // Traverse the unsorted list of nodes to find total length
    for (temp_node = ListPointer; temp_node != NULL; temp_node = temp_node->getNextPointer())
        length ++;
    
    Node* arr = new Node[length+1]; // ask  memory manager for an array of node pointers
    
    if (arr != NULL) { // Ask if we got the Heap space
        for (temp_node = ListPointer; temp_node != NULL; temp_node = temp_node->getNextPointer()){
            arr[c] = *temp_node;
            c++;
        }
        
        do { // sort dynamic array into ascending order (bubble sort)
            done = true;
            for (int x = 0; x < length-1; x++) {
                if ( calcStringSum(arr[x].getNodeData()) > calcStringSum(arr[x+1].getNodeData()) ) { // need to swap
                    done = false;
                    Node t = arr[x];
                    arr[x] = arr[x+1];
                    arr[x+1] = t;
                }
            }
        } while(!done);

        // ------------------------------ 1B.ii ------------------------------ //
        // The sorted array list will then be loaded to a new linked list
        // which retains the sorted order from lowest at the front to highest
        // at the last.
        
        int z = 0;
        
        // since original list length didn't change, I reused it and overwrote
        // with newly sorted values from array list
        for (temp_node = ListPointer; temp_node != NULL; temp_node = temp_node->getNextPointer()){
            temp_node -> setNodeData(arr[z].getNodeData());
            z++;
        }
        
        // ------------------------------ 1C. ------------------------------ //
        // The original list and the array list will then be deleted and
        // the sorted list will replace the original list within the program.
        
        delete [] arr; // Return array list to memory manager
        
        return true; // return successful sort
    }
    else // otherwise insufficient heap resources
        cout << "Insufficient Heap resource." << endl;  // If we get here the Heap is out of space
    
    return false; // return unsuccesful sort
}



int main () {
    BagList A;  // declare a Container object
    string udata;
    bool cont = true;
    char sel;
    while (!cin.eof() && cont == true) {
        cout << "Enter your function: Add, Delete, Exit, Find, List, Sort: ";
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
                // ------------------------------ 1A. ------------------------------ //
                // Create a new menu entry in the main of the program which allows the user to produce this sorted list.
                case 's': case 'S': {
                    if (A.sort())
                        cout << "Sucessfully sorted!" << endl;
                    else
                        cout << "Unsucessful sort" << endl;
                    
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