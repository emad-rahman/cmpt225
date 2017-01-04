/*
 * File:              EKTAppV2.cpp
 *
 * Class Description: main file for english-klingon translator
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              Aug 2016
 *
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

#include "TranslatorV2.h"
#include "EtoK.h"

using namespace std;


int main(int argc, char* argv[]){
  TranslatorV2 hashTable;

  string filename = "dataFile.txt";
  string line;
  //opening file - checks for errors opening file
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while (getline (myfile,line))
    {
      EtoK temp(line); //stores each line into temp object of EtoK
      hashTable.add(temp); //stores the temp EtoK object into hashTable
    }
    myfile.close();
  }else {
    cout << "Unable to open file"; 
  }

  //checks to the display argument from command line
  if(argc > 1){
    string temp1 = argv[1];
    if(temp1.compare("display") == 0){
      hashTable.print();
      return 0;
    }
  }

  cout << "*************************************************" << endl;
  cout << "Enter words you want to translater (one per line): " << endl << endl;
  string aLine = "";
  string English = "";
  EtoK arr[947]; //stores users words that he/she wants translated
  int index = 0;

  //populates array of strings with users words
  while(getline(cin, aLine)){
    stringstream ss(aLine);
    ss >> English;
    arr[index].setEng(English); // = English;
    index++; 
  }
 
  //translates english into klingon
 for(int i = 0; i < index; i++){
    string temp2 = hashTable.translate(arr[i]);
    cout << temp2 << endl;
 }

  return 0;
}