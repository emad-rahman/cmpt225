/*
 * File:              EKTApp.cpp
 *
 * Class Description: main file for english-klingon translator
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              July 2016
 *
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

#include "BstNode.h"
#include "BstNode.cpp"
#include "Translator.h"
#include "Translator.cpp"
#include "EtoK.h"

using namespace std;


int main(int argc, char* argv[]){
  Translator<EtoK> myADT; //creating an object myADT of Translator
  string filename = "dataFile.txt";
  string line;
  //opening file - checks for errors opening file
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while (getline (myfile,line))
    {
      EtoK temp(line); //stores each line into temp object of EtoK
      myADT.add(temp); //stores the temp EtoK object into myADT
    }
    myfile.close();
  }else {
    cout << "Unable to open file"; 
  }

  //checks to the display argument from command line
  if(argc > 1){
    string temp = argv[1];
    if(temp.compare("display") == 0){
      myADT.printInOrder();
      return 0;
    }
  }


  cout << "*************************************************" << endl;
  cout << "Enter words you want to translater (one per line): " << endl << endl;
  string aLine = "";
  string English = "";
  string arr[1000]; //stores users words that he/she wants translated
  int index = 0;

  //populates array of strings with users words
  while(getline(cin, aLine)){
    stringstream ss(aLine);
    ss >> English;
    arr[index] = English;
    index++; 
  }

  //translates english into klingon
 for(int i = 0; i < index; i++){
    myADT.findNode(arr[i]);
 }
  return 0;
}