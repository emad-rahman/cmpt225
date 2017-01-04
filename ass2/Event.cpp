/********************************************************************
 * File: 		   Event.cpp
 *
 * Description:    Event class implementation 
 *
 * Authors: 	   Emadur Rahman
 *		    	   Eric Feng
 *
 * Creation Date: June 19, 2016
********************************************************************/
#include "Event.h"
#include <cstdlib>

using namespace std;

//constructors
Event::Event(){
	type = 'F';
	time = 0;
	length = 0;
}
Event::Event(int a, int b){
	time = a;
	length = b;
	if(length == 0){
		type = 'D';
	}else {
		type = 'A';
	}
}

//getters
char Event::getType() const{
	return type;
}
int Event::getTime() const{
	return time;
}
int Event::getLength() const{
	return length;
}

//setters
void Event::setType(char x){
	type = x;
}
void Event::setTime(int x){
	time = x;
}
void Event::setLength(int x){
	length = x;
}