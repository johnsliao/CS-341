// John Liao
// CS 341 - Fall 2015
// Homework # 4
// main.cpp

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
    Customer (int m) {timeToServe = 1+rand()%m;}
    Customer* putOneCustomer (Customer*, int, int, int);
    Customer* getNextPointer ();
    Customer* getPriorPointer ();
    
    int getCustomerNumber ();
    int getTimeToServe();
    int getEntryMin();
    
    void putNextPointer (Customer*);
    void putPriorPointer (Customer*);
    void setTimeToServe (int);
    void decrementTimeToServe();
    
private:
    Customer* nextPtr;
    Customer* priorPtr;
    
    int customerNumber; // customer number
    int timeToServe; // set time needed for customer task
    int entryMin; // time customer entered line
};

int Customer::getEntryMin() {
    return entryMin;
}
Customer* Customer::getNextPointer (){
    return nextPtr;
}

int Customer::getTimeToServe (){
    return timeToServe;
}

void Customer::decrementTimeToServe() {
    timeToServe--;
}

void Customer::putNextPointer (Customer* x){
    this->nextPtr = x;
}
Customer* Customer::getPriorPointer (){
    return priorPtr;
}
void Customer::putPriorPointer (Customer* x){
    this->priorPtr = x;
}

Customer* Customer::putOneCustomer (Customer* x, int y, int z, int q) {
    Customer* temp = NULL;
    if (temp = new Customer(q)) {
        temp->nextPtr = x;
        temp->priorPtr = NULL;
        temp->customerNumber = y;
        temp->entryMin = z;
    }
    return temp;
}
int Customer::getCustomerNumber() {
    return customerNumber;
}

void Customer::setTimeToServe(int input) {
    timeToServe = input;
}

class DoubleLinkList {  // My Container class
public:
    DoubleLinkList ();
    bool putCustomer (int, int, int);  // Admit to list
    void getListReverse (int);
    bool dequeue();
    Customer* getFirstCustomer(); // return first customer that is being serviced
    
private:
    Customer* FwdListPointer;
    Customer* RevListPointer;
    Customer* previous;
};

Customer* DoubleLinkList::getFirstCustomer() {
    return RevListPointer;
}

bool DoubleLinkList::dequeue() {
    
    Customer* delPtr;
    Customer* temp = NULL;
    bool status = false;
    delPtr = RevListPointer;
    if (delPtr != NULL) {
        if (FwdListPointer == delPtr)
            FwdListPointer = FwdListPointer->getNextPointer();
        else
        {
            temp = delPtr->getPriorPointer();
            temp->putNextPointer(delPtr->getNextPointer());
        }

        if (RevListPointer == delPtr)
            RevListPointer = RevListPointer->getPriorPointer();
        else
        {
            temp = delPtr->getNextPointer();
            temp->putPriorPointer(delPtr->getPriorPointer());
        }
        
        delete delPtr;
        status = true;
    }
    return status;
}

DoubleLinkList::DoubleLinkList ()
{
    FwdListPointer = RevListPointer = previous = NULL;
}

bool DoubleLinkList::putCustomer (int s, int e, int o) {
    bool x = false;
    Customer* temp1;
    Customer A(o);
    
    temp1 = A.putOneCustomer (FwdListPointer, s, e, o);
    
    if (temp1 != NULL)
    {	if (FwdListPointer == NULL && RevListPointer == NULL)
        FwdListPointer = RevListPointer = temp1;
    else
    {
        FwdListPointer->putPriorPointer (temp1);
        FwdListPointer = temp1;
    }
        x = true;
    }
    return x;
}

void DoubleLinkList::getListReverse(int minuteNum) {
    Customer* temp;
    Customer* temp2;
    
    int totalWaitTime; // temp storage for cumulative wait time ahead
    
    if (RevListPointer == NULL)
        cout << minuteNum << "\t\t None" << endl;
    
    for (temp = RevListPointer; temp != NULL; temp = temp->getPriorPointer()) {
        cout << minuteNum << "\t\t\t";
        cout << temp->getCustomerNumber() << "\t\t\t\t";
        cout << temp->getEntryMin() << "\t\t\t\t\t";
        cout << temp->getTimeToServe() << "\t\t\t\t\t";
        
        temp2 = RevListPointer;
        totalWaitTime = 0;
        
        for(; temp2 != temp; temp2 = temp2->getPriorPointer()) { // add up all times for customers in front of current customer
            totalWaitTime += temp2->getTimeToServe();
        }
        
        cout << totalWaitTime << "\t\t\t\t\t";
        cout << temp->getTimeToServe()+totalWaitTime << endl;
        
    }
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

}

int main () {
    DoubleLinkList A;
    int customerCounter = 1;
    int minNumber = 1;
    int totalSimulationTime = 0, maxIntervalEnterQueue = 0, maxIntervalServePerson = 0, timeUntilNextCustomer = 0;
    bool validInput = false;
    string trash;
    // Gather user input information. Prompt again if invalid input, i.e. non-numeric.
    
    while(!validInput) {
        cout << "Enter the length of time simulation should run (minutes): ";
        
        cin >> totalSimulationTime;
        
        if (!cin.eof() && cin.good())
            validInput = true;
        else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin >> trash; //remove the bad input from the cin stream by throwing it into the trash string
        }
    }
    
    validInput = false;
    
    while(!validInput) {
        cout << "Enter maximum interval between individual people entering the queue (minutes): ";
        cin >> maxIntervalEnterQueue;
        
        if (!cin.eof() && cin.good())
            validInput = true;
        else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin >> trash; //remove the bad input from the cin stream by throwing it into the trash string
        }
    }
    
    validInput = false;
    
    while(!validInput) {
        cout << "Enter maximum interval of time to serve an individual person in the queue (minutes): ";
        cin >> maxIntervalServePerson;
        
        if (!cin.eof() && cin.good())
            validInput = true;
        else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin >> trash; //remove the bad input from the cin stream by throwing it into the trash string
        }
    }
    
    cout << endl;
    
    maxIntervalEnterQueue--; // account for rand() mod
    maxIntervalServePerson--; // account for rand() mod
    
    timeUntilNextCustomer = 1+rand()%(maxIntervalEnterQueue); // initialize time until next customer

    A.putCustomer(customerCounter, 1, maxIntervalServePerson); // initialize first customer
    
    cout << "Minute # | Customer # | Entry Minute | Service Time Remaining | Wait Time remaining | Minutes remaining until Service is finished" << endl;
    
    for(;minNumber<=totalSimulationTime;minNumber++) {
        
        if (A.getFirstCustomer() != NULL) { // check if any customers in line
            if (A.getFirstCustomer()->getTimeToServe() == 0)
                A.dequeue();
            
            if (A.getFirstCustomer() != NULL) // check if any customers in line
                A.getFirstCustomer()->decrementTimeToServe();
        }
        
        if (timeUntilNextCustomer == 0) { // new customer! add to queue and reset timer
            timeUntilNextCustomer = 1 + rand()%(maxIntervalEnterQueue);
            A.putCustomer(++customerCounter, minNumber, maxIntervalServePerson);
        }

        A.getListReverse(minNumber); // print out customers in line and relevant information
        timeUntilNextCustomer--;
    }
    return 0;
}