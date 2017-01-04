/*
 * File:              EtoK.cpp
 *
 * Class Description: implementation for the object that will hold english
 					  and klingon translations
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              July 2016
 *
 */
#include "EtoK.h"

//default constructor
EtoK::EtoK(){
	engAndKli = "";
}//end default constructor


//constructor
//Description: sets the data for the english to klingon
//				translation
EtoK::EtoK(string newElement){
	engAndKli = newElement;
}


//Description: getter, returns translation
string EtoK::getEngAndKli(){
	return engAndKli;
}

//Description setter, sets translation
void EtoK::setEndAndKli(string newWord){
	engAndKli = newWord;
}