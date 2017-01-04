/*
 * File:              Hash.cpp
 *
 * Class Description: implementation for the object that will hold the key index
 * 					  of each word
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              Aug 2016
 *
 */
#include "Hash.h"

//default constructor
Hash::Hash(){
	KeyIndex = 0;
}//end default constructor

//parameterised constructor
//Description: takes a key and the table size to set it's key index
Hash::Hash(EtoK Key, const int TableSize){
	int len = Key.getEng().length();
	KeyIndex = 0;
	int j = len-1;

	for(int i = 0; i < len; i++){
		KeyIndex += ((int)Key.getEng()[i] - ASCII_CONVERSION) * pow(32, j);
		j--;
	}

	KeyIndex = abs(KeyIndex % TableSize);
}//end parameterised constructor

//Description: getter, returns the value of the key index
int Hash::getKeyIndex(){
	return KeyIndex;
}