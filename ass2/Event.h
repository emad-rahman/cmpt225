/********************************************************************
 * File: 		   Event.h
 *
 * Description:    Header for the Event class - stores the event 
 *			   	   type, time of event, and duration of event
 *
 * Authors: 	   Emadur Rahman
 *		    	   Eric Feng
 *
 * Creation Date: June 19, 2016
********************************************************************/
#include <cstdlib>

#pragma once

using namespace std;

class Event{
private:
	char type;
	int time;
	int length;
public:
	//constructors
	Event();
	Event(int a, int b);

	//getters 
	char getType() const;
	int getTime() const;
	int getLength() const;

	//setters
	void setType(char x);
	void setTime(int x);
	void setLength(int x);
};