/********************************************************************
 * File:              Queue.h
 *
 * Description:       header for Queue calss - stores events in an
 *                    array
 *
 * Class invariants:  FIFO or LILO
 *
 * Authors:           Emadur Rahman
 *                    Eric Feng
 *
 * Creation Date:     June 19, 2016
********************************************************************/
#include <cstdlib>
#include "Event.h"
#include "EmptyDataCollectionException.h"

#pragma once

using namespace std;

class Queue{
private:
   Event elements[100]; 
   int numElements;
   int startPosition;
public:
   //default constructor
   Queue();

   // Description: Returns "true" is this queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
      
   // Description: Adds newElement to the "back" of this queue and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(const Event& newElement);
      
   // Description: Removes the element at the "front" of this queue and 
   //              returns "true" if successful, otherwise "false".
   // Precondition: This queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Retrieves (but does not remove) the element at the  
   //              "front" of this queue and returns it.
   // Precondition: This queue is not empty.
   // Postcondition: This queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this queue is empty.
   // Time Efficiency: O(1)
   Event peek() const throw(EmptyDataCollectionException);  
};