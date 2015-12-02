// John Liao
// CS 341 FALL 2015
// HW #2
// main.cpp

#include <iostream>
using namespace std;

int main () {
    int input;
    int num_inputs = 0;
    int* temp; // temp array pointer
    int* Arr = new int[1]; // initalize array of size 1
    
    bool exit = false;
    
    do {
        if (num_inputs != 0) {
            cout << "Current array is ";
            
            for (int x = 0; x<num_inputs; x++) {
                cout << *(Arr+x) << " ";
            }
            cout << "hello" << endl;
        }
        
        cout << "Enter an input: ";
        
        cin >> input;
        
        cout << "WEE" << endl;
        
        if (!cin.eof() && cin.good()) {
            cout <<"Enter" <<endl;
            num_inputs++;
            
            temp = new int[num_inputs]; // allocate new space
            
            if (temp != NULL) { // test if Heap memory is exhausted
                for (int i = 0; i < num_inputs; i++) {
                    *(temp+i) = *(Arr+i);
                }
                
                *(temp + num_inputs - 1) = input; // Add input to the end of the array. -1 since array index starts at 0
                
                delete [] Arr; // delete previous version of array
                Arr = temp;
                
                cout << "New array is: ";
                
                for (int x=0; x < num_inputs; x++) {
                    cout << *(Arr+x) << " ";
                }
                cout << endl;
            }
            else {
                cout << "Insufficient Heap resource." << endl;  // If we get here the Heap is out of space
                exit = true;
            }
            cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" <<endl;
        }
        else {
            if (!cin.eof())
                cout << " One or more invalid inputs" << endl;
            exit = true;
        
        
        
    } while (!exit);
    
    return EXIT_SUCCESS;
}