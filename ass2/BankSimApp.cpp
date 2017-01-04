/********************************************************************
 * File: 		   BankSimApp.cpp
 *
 * Description:    A simulation application - contains the main() 
 *                 function
 *
 * Authors: 	   Emadur Rahman
 *		    	   Eric Feng
 *
 * Creation Date: June 19, 2016
********************************************************************/
#include <iostream>
#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "Queue.h"
#include "PQueue.h"
#include "Node.h"
#include <sstream>
#include <string>
#include <iomanip> //using this to align numbers (i.e. setw())

using namespace std;

int main(int argc, char* argv[]){

	string line;
	int time, length;
	int numPeople = 0;
	int previous = 1;
	double sum, avg;
	Queue queue;
	PQueue pqueue;

	//Description: Reads in pairs of numbers intrepreted as "time" and "length"
	//			   and stores it in the ADT Event. All Events are stored in a
	//			   Queue
	while(getline(cin, line)){
		stringstream ss(line);
		ss >> time >> length;
		Event temp(time,length);
		queue.enqueue(temp);
	}

	//Description: 1) Stores Events that are in queue into priority queue and then
	//			      removing those events from the queue. 
	//			   2) Calculates the number of people in line(queue)
	//             3) Sums up the wait time of each customer
	while(!queue.isEmpty()){
		int Dtime = queue.peek().getLength() + previous;
		previous = Dtime;
		pqueue.enqueue(queue.peek());
		queue.dequeue();
		if(!queue.isEmpty() && queue.peek().getTime() < Dtime){
			sum +=(Dtime - queue.peek().getTime());
		}else if(!queue.isEmpty()){
			previous = queue.peek().getTime();
		}
		numPeople++;
	}
	
	avg = sum / (numPeople); //calculates average
	cout << endl << "Simulation Begins " << endl;

	//Description: Displays stats on events in the priority queue and then removes the 
	//			   events when finished 
	while(!pqueue.isEmpty()){
		if(pqueue.peek().getType() == 'A'){
			cout << "Processing an arrival event at time: \t" << setw(4) << pqueue.peek().getTime() << endl;
		}else if(pqueue.peek().getType() == 'D'){
			cout << "Processing a departure event at time: \t" << setw(4) << pqueue.peek().getTime() << endl;
		}
		pqueue.dequeue();
	}

	cout << "Simulation Ends" << endl << endl;
	
	//Displaying final statistics 
	cout << "Final Statistics:" << endl; 
	cout <<"\tTotal number of people processed: " << setw(3) << numPeople << endl;
	cout <<"\tAverage amount of time spent waiting: "  << fixed << setprecision(1) << avg << endl;



	return 0;
}