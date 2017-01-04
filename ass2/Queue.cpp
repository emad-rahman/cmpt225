/********************************************************************
 * File:              Queue.cpp
 * 
 * Description:       Queue class implementation
 *
 * Class invariants:  FIFO or LILO
 *
 * Authors:           Emadur Rahman
 *                    Eric Feng
 *
 * Creation Date:     June 19, 2016
********************************************************************/
#include <cstdlib>
#include "Queue.h"

using namespace std;

//Default constructor
Queue::Queue(){
	Event elements[100];
	numElements = 0;
	startPosition = 0;
}

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool Queue::isEmpty() const{
	if(numElements == 0){
		return true;
	}
	return false;
}

// Description: Adds newElement to the "back" of this queue and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool Queue::enqueue(const Event& newElement){
	if(numElements >= 100){
		return false;
	}else{
		elements[numElements] = newElement;
		numElements++;
		return true;
	}
	
}

// Description: Removes the element at the "front" of this queue and 
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool Queue::dequeue(){
	if(numElements == 0){
		return false;
	}
	startPosition++;
	numElements--;
	return true;
}

// Description: Retrieves (but does not remove) the element at the  
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
Event Queue::peek() const throw(EmptyDataCollectionException){
	if(isEmpty()){
		try{
			throw EmptyDataCollectionException();
		}
		catch(logic_error()){

		}
	}
	return elements[startPosition];
}