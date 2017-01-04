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
#include <iostream>
using namespace std;

class EtoK{
private:
	string engAndKli;
	string Eng;
public:
	//constructors
	EtoK();
	EtoK(string newElement);

	//getters
	string getEngAndKli();
	string getEng();
	//setters
	void setEngAndKli(string newWord);
	void setEng(string newWord);
};