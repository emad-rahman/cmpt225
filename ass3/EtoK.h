/*
 * File:              EtoK.h
 *
 * Class Description: header for the object that will hold english
 					  and klingon translations
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              July 2016
 *
 */
#pragma once
#include <string>
#include "BstNode.h"
using namespace std;

class EtoK{
private:
	string engAndKli;
public:
	//constructor
	EtoK();
	EtoK(string newElement);

	//getter
	string getEngAndKli();
	//setter
	void setEndAndKli(string newWord);
};