/*
 * File:              TranslatorV2.h
 *
 * Class Description: header for the data collection ADT
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              Aug 2016
 *
 */
#pragma once
#include "EtoK.h"
#include "Hash.h"
#include <string>
#include <iostream>

using namespace std;

class TranslatorV2{
private:
	//sets the default table size
	//precondition: must be prime number
	const static int defaultTableSize = 947; 
	//the number of elements in each index of the hash table
	const static int depth = 5;	
	//2D array of size [947][5]
	EtoK translator[defaultTableSize][depth];
	//number of elements in the array
	int elementCount;

public:
	TranslatorV2(); //default constructor
	
	//Description: Translates an english word into its Klingon
	//				translation
	//Postcondition: will always return something
	//				- if word is in translator: returns translated word
	//				- if word is not in translator: returns 
	//					word:<not found>
	string translate(EtoK Key);

	//getters
	int getTableSize();
	int getElementCount();

	//Description: tells if an index in translator[index1][index2] is
	//				is empty or not
	//precondition: index 1 must be < defaultTableSize and
	//				index 2 must be < depth
	bool isEmpty(int index1, int index2); // checks if there is an item in 

	//Description: adds an element to translator[x][y]
	//postcondtion: adds element in O(1)
	void add(EtoK newElement);

	//Description: sorts array in alphabetical order - will be
	//				used to sort array before printing all
	//				elements in the array
	//postcondition: returns a sorted arry; uses bubble sort - O(n^2)
	void sort(string *arr);

	//Description: prints all elements in translator[x][y]
	//postcondition: prints in O(n)
	void print();
};