
/*
 * filename: MyADT.h or MyADT.cpp
 * 
 * Class Description: A data collection ADT class to satisfy Assn 1's requiremetns.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicate).
 *                   - Once it has been ascertained that the element has not already been 
 *                     inserted, its data structure allows insertion in O(1)
 *                   - Once the element to be removed as been found, 
 *                     its data structure allows removal in O(1).
 *                   - Its data structure is resizable: when full, it expands to accommodate 
 *                     new element insertions. This is done unbeknown to the client code.
 *
 * Creation date: 
 * Author:
 */
 

 #include <cstdlib>
 #include "Profile.h"
 #include "MyADT.h"
 #include <string>
 #include <cctype>
#include <iostream>
 
 using namespace std;
        
 MyADT::MyADT(){
     numElements = 0;
     arr = new Profile[10];
 }

	// Description: Returns the total of elements currently stored in MyADT.
	int MyADT::getElementCount() const{
        return numElements;
	}

	// Description: Inserts an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
	bool MyADT::insert(const Profile& newElement){
        for(int i = 0; i < 10; i++){
            if(arr[i] == newElement){
                return false;
            }
        }
        arr[numElements] = newElement;
        numElements++;
        return true;
	}

	// Description: Removes an element. 
	// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.	
	bool MyADT::remove(const Profile& toBeRemoved){
        for(int i = 0; i < 10; i++){
            if(arr[i] == toBeRemoved){
                arr[i] = arr[10];
                numElements--;
                return true;
            }
        }
        return false;
	}

	// Description: Searches for target element.
	Profile* MyADT::search(const Profile& target){
        for(int i = 0; i < 10; i++){
            if(arr[i] == target){
                Profile *thisGuy;
                return thisGuy;
            }
        }
	}

	// Description: Removes all elements.
	void MyADT::removeAll(){
        numElements = 0;
        arr = new Profile[10];
	}

    
    Profile* MyADT::getArray(){
        return arr;
    }
    
	// Description: Prints all elements stored in MyADT.
	ostream & operator<<(ostream & os, const MyADT& rhs){
        os << "\nHere is the list of members: \n";
        for(int i = 0; i < rhs.getElementCount(); i++){
            os << rhs.arr[i];
        } 
        return os;
	}

 