/********************************************************************
 * File:              PQueue.h
 *
 * Description:       header for PQueue calss - stores events in
 *                    priority order
 *
 * Class invariants:  The elements stored in this Priority Queue are 
 *                    always sorted.
 *
 * Authors:           Emadur Rahman
 *                    Eric Feng
 *
 * Creation Date:     June 19, 2016
********************************************************************/
#include <cstdlib>
#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "Node.h"

#pragma once
 
using namespace std;

   //Class Invariant: 
class PQueue{
private:
   Node *head; 
public:
   // Constructor
   PQueue();

   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
  
   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.   
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.           
   bool enqueue(const Event& newElement);
   
   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   bool dequeue();

   // Description: Retrieves (but does not remove) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   Event peek() const throw(EmptyDataCollectionException); 
};