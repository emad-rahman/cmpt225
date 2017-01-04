/*
 * File:              TranslatorV2.h
 *
 * Class Description: implementation for the data collection ADT
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              Aug 2016
 *
 */
#include "TranslatorV2.h"

//default constructor
TranslatorV2::TranslatorV2(){
	elementCount = 0;
}// end default constructor


//Description: Translates an english word into its Klingon
//				translation
//Postcondition: will always return something
//				- if word is in translator: returns translated word
//				- if word is not in translator: returns 
//					word:<not found>
string TranslatorV2::translate(EtoK Key){
	int index = Hash(Key, defaultTableSize).getKeyIndex();
	bool same = false;
	
	//if the element at [x][1] is empty then [x][2], [x][3], ... [x][5] 
	//will all be empty. Therefore, onle [x][0] will have an EtoK object
	if(isEmpty(index, 1) && translator[index][0].getEngAndKli() != ""){
		return translator[index][0].getEngAndKli();
	}
	for(int i = 0; i < depth; i++){
		if(!isEmpty(index, i)){
			for(int j = 0; j < Key.getEng().length(); j++){
				if(translator[index][i].getEng()[j] != Key.getEng()[j]){
					same = false;
					break;
				}else{
					same = true;
				}
			}
		}
		if(same == true && translator[index][i].getEngAndKli() != ""){
			return translator[index][i].getEngAndKli();
		}
	}
	//does this if word is not in the translator
	EtoK notInTranslator(Key.getEng() + ":<not found>");
	return notInTranslator.getEngAndKli();
}

//Description: getter, gets the defaultTableSize
int TranslatorV2::getTableSize(){
	return defaultTableSize;
}

//Description: getter, gets the number of elements in the data collection
int TranslatorV2::getElementCount(){
	return elementCount;
}

//Description: tells if an index in translator[index1][index2] is
//				is empty or not
//precondition: index 1 must be < defaultTableSize and
//				index 2 must be < depth
bool TranslatorV2::isEmpty(int index1, int index2){
	if(index1 > defaultTableSize || index2 > depth){
		return false;
	}
	if(translator[index1][index2].getEngAndKli().length() == 0){
		return true;
	}
	return false;
}

//Description: adds an element to translator[x][y]
//postcondtion: adds element in O(1)
void TranslatorV2::add(EtoK newElement){
	for(int i = 0; i < depth; i++){
		if(isEmpty(Hash(newElement, defaultTableSize).getKeyIndex(), i)){
			translator[Hash(newElement, defaultTableSize).getKeyIndex()][i] = newElement;
			elementCount++;
			break;
		}
	}
}

//Description: sorts array in alphabetical order - will be
//				used to sort array before printing all
//				elements in the array
//postcondition: returns a sorted arry; uses bubble sort - O(n^2)
void TranslatorV2::sort(string *arr){
	int arrIndex = 0;
	for(int i = 0; i < defaultTableSize; i++){
		for(int k = 0; k < depth; k++){
			if(!isEmpty(i, k)){
				arr[arrIndex] = translator[i][k].getEngAndKli();
				arrIndex++;
			}
		}
	}

	//bubble sort
	string temp;
	for(int i = 0; i < elementCount; i++){
		for(int j = 0; j < elementCount-1; j++){
			if(arr[j].compare(arr[j+1]) >= 0){
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//Description: prints all elements in translator[x][y]
//postcondition: prints in O(n)
void TranslatorV2::print() {
	string *arr = new string[elementCount];
	sort(arr);
	for(int i = 0; i < elementCount; i++){
		cout << arr[i] << endl;
	}
}











