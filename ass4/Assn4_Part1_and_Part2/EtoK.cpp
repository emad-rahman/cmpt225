/*
 * File:              EtoK.cpp
 *
 * Class Description: implementation for the object that will hold english
 					  and klingon translations
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              Aug 2016
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
	for(int i = 0; i < newElement.length(); i++){
		if((int)newElement[i] == 58){
			Eng = newElement.substr(0, i);
			break;
		}
	}
}


//Description: getter, returns translation
string EtoK::getEngAndKli(){
	return engAndKli;
}

//Description: getter, returns only the english portion
string EtoK::getEng(){
	return Eng;
}

//Description setter, sets translation
void EtoK::setEngAndKli(string newWord){
	engAndKli = newWord;
}

//Description: setter, sets the english word
void EtoK::setEng(string newWord){
	Eng = newWord;
}