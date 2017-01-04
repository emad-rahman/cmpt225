/********************************************************************
 * File:              PQueue.cpp
 *
 * Description:       PQueue class implementation
 *
 * Class invariants:  The elements stored in this Priority Queue are 
 *                    always sorted.
 *
 * Authors:           Emadur Rahman
 *                    Eric Feng
 *
 * Creation Date:     June 19, 2016
********************************************************************/
#include "PQueue.h"
#include <cstdlib>



using namespace std;

//constructor
PQueue::PQueue(){
	head = new Node;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PQueue::isEmpty() const{
	if (head == NULL){
		return true;
	}
	return false;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.  
// NOTE: This takes one event and calculates its departure event and then adds both
// 		 to the PQueue in sorted order (takes one - gives two)
bool PQueue::enqueue(const Event& newElement){
	int time = newElement.getTime();
	char type = newElement.getType();
	int length = newElement.getLength();

	Node *previous;
	Node *current = head;
	Node *tail = head;

	while(tail->next != NULL){
		tail = tail->next;
	}

	//Store arrival/departure event before the last node
	while(current->next != NULL){
		if(time < current->data.getTime()){
			Node *temp = new Node;
			temp->data = newElement;
			temp->next = current;
			previous->next = temp;

			int newTime = 0;
			if(tail->data.getTime() < time){
				newTime = time + length;
			}else{
				newTime = tail->data.getTime() + length;
			}
			Event newEvent(newTime, 0);
			Node *current2 = current;
			Node *previous2 = temp;
			while (current2->next != NULL){
				if(newTime < current2->data.getTime()){
					Node* temp2 = new Node;
					temp2->data = newEvent;
					temp2->next = current2;
					previous2->next = temp2;
					return true;
				}
				previous2 = current2;
				current2 = current2->next;
			}
			if(newTime < current2->data.getTime()){
				Node* temp2 = new Node;
				temp2->data = newEvent;
				temp2->next = current2;
				previous2->next = temp2;
				return true;
			}else{
				Node *temp2 = new Node;
				temp2->data = newEvent;
				temp2->next = NULL;
				current2->next = temp2;
				return true;
			}

		}
		previous = current;
		current = current->next;
	}

	//Stores arrival/departure event if it comes after the last node OR 
	//PQueue is empty
	if(time < current->data.getTime()){
		Node *temp = new Node;
		temp->data = newElement;
		temp->next = current;
		previous->next = temp;

		int newTime = 0;
		if(tail->data.getTime() < time){
			newTime = time + length;
		}else{
			newTime = tail->data.getTime() + length;
		}
		Node *temp2 = new Node;
		Event newEvent(newTime, 0);
		temp2->data = newEvent;
		temp2->next = NULL;
		current->next = temp2;
		return true;
	 }else{
		Node *temp = new Node;
		temp->data = newElement;
		temp->next = NULL;
		current->next = temp;

		int newTime = time + length;

		Event newEvent(newTime, 0);
		Node *temp2 = new Node;
		temp2->data = newEvent;
		temp2->next = NULL;
		temp->next = temp2;
		return true;
	}
	return true;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
bool PQueue::dequeue(){
	if(isEmpty()){
		return false;
	}
	head = head->next;
	return true;
}

// Description: Retrieves (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
Event PQueue::peek() const throw(EmptyDataCollectionException){
	if(isEmpty()){
		try{
			throw EmptyDataCollectionException();
		}
		catch(logic_error()){

		}
	}
	return head->data;
}

