// John Liao
// CS 341 - Fall 2015
// HW # 3
// main.cpp

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define XMAXSIZE 100

// I set up a Node class to interact with the array container class.
// The Array class consists of an array of node pointers. All corresponding functions in the Array class have been modified to handle pointers. Similarly, main() has been changed as well.
// I chose to keep the array class static with a XMAXSIZE of 100.

class Node {
public:
    Node () {}
    Node (string data) {X = data;}
    string getData() {return X;}
private:
    string X;
};

class Array {
public:
    Array() {listIdx = -1;}
    bool addElement (Node*);
    bool deleteElement (Node*);
    bool findElement (Node*);
    string listElements ();
private:
    Node * X [XMAXSIZE];
    int listIdx;
};

bool Array::addElement (Node * data) {
    bool ret = true;
    if (listIdx < XMAXSIZE-1){
        X[++listIdx] = data;
    }
    else
        ret = false;
    return ret;
}

bool Array::findElement (Node * data) {
    bool found = false;
    for (int i = 0; i < listIdx+1 && found == false; i++){
        if (X[i]->getData() == data->getData()){
            found = true;
        }
    }
    return found;
}

bool Array::deleteElement(Node * data) {
    bool found = false;
    if (findElement (data)) {
        for (int i = 0; i < listIdx+1 && found == false; i++){
            if (X[i]->getData() == data->getData()){
                int idxToDelete = i;
                int j = idxToDelete + 1;
                for (; j <= listIdx; j++)
                    X[j-1] = X [j];
                X[listIdx--] = nullptr;
                found = true;
            }
        }
    }
    return found;
}

string Array::listElements (){
    string elementList = "";
    if (listIdx > -1){
        for(int i = 0; i <= listIdx; i++)
            elementList += " " + X[i]->getData();
    }
    return elementList;
}

int main () {
    Array A;
    string udata;
    bool cont = true;
    char sel;
    Node* temp;
    
    while (!cin.eof() && cont == true) {
        cout << "Enter your function: Add, Find, List, Delete, Exit or control-z: ";
        cin >> sel;
        if (!cin.eof()) {
            switch (sel) {
                case 'A': case 'a': {
                    cout << "Enter your string ";
                    cin >> udata;
                    if (!cin.eof()) {
                        
                        temp = new Node(udata);
                        
                        if (!A.addElement(temp))
                            cout << "Element not added. Array already full" << endl;
                    }
                    break;
                }
                case 'E': case 'e': {
                    cont = false;
                    break;
                }
                case 'D': case 'd': {
                    cout << "Please Enter User Data value to delete: ";
                    cin >> udata;
                    if (!cin.eof()) {
                        
                        temp = new Node(udata);
                        
                        
                        if (A.deleteElement (temp)) {
                            cout << "Entry " << udata << " deleted" << endl;
                        }
                        else
                            cout << "Entry " << udata << " not found" << endl;
                    }
                    break;
                }
                case 'F': case 'f': {
                    cout << "Please Enter User Data value to find: ";
                    cin >> udata;
                    if (!cin.eof()) {
                        
                        temp = new Node(udata);
                        
                        if (A.findElement(temp))
                            cout << "Entry " << udata << " found" << endl; 
                        else
                            cout << "Entry " << udata << " not found" << endl;
                        
                    }
                    break;
                }
                case 'L': case 'l': {
                    string W = A.listElements();
                    if (W != ""){
                        cout << "List of Entries" << endl;  // check this placement
                        cout << W << endl;
                    }
                    else
                        cout << "List is Empty";
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
    //system ("PAUSE");
    return 0;
}
