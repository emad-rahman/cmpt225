/*
 * File:              Hash.h
 *
 * Class Description: header for the object that will hold the key index
 * 					  of each word
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              Aug 2016
 *
 */
#pragma once
#include <string>
#include "EtoK.h"
#include "math.h"
#include <cmath>

class Hash{
private:
	const static int ASCII_CONVERSION = 96;
	int KeyIndex;

public:
	//constructors
	Hash();
	Hash(EtoK Key, const int TableSize);

	//getter
	int getKeyIndex();
};