/*
 * File:              Translator.cpp
 *
 * Class Description: implementation for the data collection ADT called Translator
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              July 2016
 *
 */
#include "Translator.h"
#include <iostream>
using namespace std;

//default constructor
template<class T>
Translator<T>::Translator() : rootPtr(nullptr){
} //end default constructor


//constructor
//Description: Inserts data into root and sets left and right
//				child to nullptr
template<class T>
Translator<T>::Translator(const T& rootItem){
	rootPtr = new BstNode<T>(rootItem, nullptr, nullptr);
}//end constructor


//constructor
//Desctiption: Inserts data into root and then sets left and
//				right child to user defined BstNode pointers
template<class T>
Translator<T>::Translator(const T& rootItem, const Translator<T>* leftTreePtr, const Translator<T>* rightTreePtr){
	rootPtr = new BstNode<T>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
}//end constructor


//Description: copies a tree pointer into root
//precondition: tree is not empty
//postcondition: new tree pointer that is copy of the first tree pointer
template<class T>
BstNode<T>* Translator<T>::copyTree(BstNode<T>* treePtr) const{
	BstNode<T>* newTreePtr = nullptr;
	if(treePtr != nullptr){
		newTreePtr = new BstNode<T>(treePtr->getElement(), nullptr, nullptr);
		newTreePtr->setLeft(copyTree(treePtr->getLeft()));
		newTreePtr->setRight(copyTree(treePtr->getRight()));
	}
	return newTreePtr;
}


//copy constructor
template<class T>
Translator<T>::Translator(const Translator<T>& treePtr){
	rootPtr = copyTree(treePtr.rootPtr);
}//end copy constructor


//Description: deletes a tree
//precondition: tree is not empty
//postcondition : tree is empty
template<class T>
void Translator<T>::destroyTree(BstNode<T>* subTreePtr) {
	if (subTreePtr != nullptr) {
		destroyTree(subTreePtr->getLeft()); 
		destroyTree(subTreePtr->getRight()); 
		delete subTreePtr;
	} 
}


//destructor
template<class T>
Translator<T>::~Translator(){
	destroyTree(rootPtr);
}//end destructor


//Description: adds node to tree
//postcondition: adds node into tree sorted
template<class T>
bool Translator<T>::add(const T& newData){
	BstNode<T>* newNodePtr = new BstNode<T>(newData); 
	rootPtr = insertInorder(rootPtr, newNodePtr);
	return true;
}


//Description: inserts in inorder
//postcondition: adds node into a tree in inorder sorting
template<class T>
BstNode<T>* Translator<T>::insertInorder(BstNode<T>* subTreePtr, BstNode<T>* newNodePtr){
	if (subTreePtr == nullptr){
		return newNodePtr; 
	}else if(subTreePtr->getElement().getEngAndKli().compare(newNodePtr->getElement().getEngAndKli()) > 0){
		BstNode<T>* tempPtr = insertInorder(subTreePtr->getLeft(), newNodePtr);
		subTreePtr->setLeft(tempPtr);
	}else{
		BstNode<T>* tempPtr = insertInorder(subTreePtr->getRight(), newNodePtr);
		subTreePtr->setRight(tempPtr);
	}
	return subTreePtr;
}


//Description: gets the data in the root
template<class T>
T Translator<T>::getRootData() const{
	return rootPtr->getElement();
}


//Description: prints all elements in tree in inorder(smallest to largest)
//precondition: tree is not empty
template<class T>
void Translator<T>::printInOrderPrivate(BstNode<T>* subTreePtr){
	if(rootPtr != nullptr){
		if(subTreePtr->getLeft() != nullptr){
			printInOrderPrivate(subTreePtr->getLeft());
		}
		cout << subTreePtr->getElement().getEngAndKli() << endl;
		if(subTreePtr->getRight() != nullptr){
			printInOrderPrivate(subTreePtr->getRight());
		}
	}else{
		cout << "Tree is Empty" << endl;
	}
}


//Description: accesses the private print method 
template<class T>
void Translator<T>::printInOrder(){
	printInOrderPrivate(rootPtr);
}


//Description: prints the translation of a work
//precondition: word is in the dictionary
template<class T>
void Translator<T>::findNodePrivate(BstNode<T>* subTreePtr, string str){
	if(rootPtr != nullptr){
		if(str.compare(subTreePtr->getElement().getEngAndKli()) < 0 && subTreePtr->getLeft() != nullptr){
			findNodePrivate(subTreePtr->getLeft(), str);
		}
		if(str.compare(subTreePtr->getElement().getEngAndKli()) > 0 && subTreePtr->getRight() != nullptr){
			findNodePrivate(subTreePtr->getRight(), str);
		}
		bool same = true;
		for(int i = 0; i < str.size(); i++){
			if(str[i] != subTreePtr->getElement().getEngAndKli()[i]){
				same = false;
			}
		}
		if(same == true){
			cout << subTreePtr->getElement().getEngAndKli() << endl;
		}
	}

}


//Description: accesses the private findNode method
template<class T>
void Translator<T>::findNode(string str){
	return findNodePrivate(rootPtr, str);
}




//Everything Below is for testing purposes: ignore

//*********************************************************************************************************************

// template<class T>
// BstNode<T>* Translator<T>::findNodePrivate(BstNode<T>* subTreePtr, string str){
// 	//cout<< "Came here" << endl;
// 	if(rootPtr != nullptr){
// 		if(str.compare(subTreePtr->getElement().getEng()) < 0){
// 			findNodePrivate(subTreePtr->getLeft(), str);
// 		}
// 		if(str.compare(subTreePtr->getElement().getEng()) > 0){
// 			findNodePrivate(subTreePtr->getRight(), str);
// 		}
// 		if(str.compare(subTreePtr->getElement().getEng()) == 0){
// 			return subTreePtr;
// 		}
// 	}
// 	return subTreePtr;
// }

// template<class T>
// BstNode<T>* Translator<T>::balancedAdd(BstNode<T>* subTreePtr, BstNode<T>* newNodePtr){
// 	if (subTreePtr == nullptr){
// 		return newNodePtr; 
// 	}else{
// 		BstNode<T>* leftPtr = subTreePtr->getLeft(); 
// 		BstNode<T>* rightPtr = subTreePtr->getRight();
// 		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
// 			rightPtr = balancedAdd(rightPtr, newNodePtr);
//         	subTreePtr->setRight(rightPtr);
//     	}else{
//     		leftPtr = balancedAdd(leftPtr, newNodePtr); 
//     		subTreePtr->setLeft(leftPtr);
// 	} // end if
// 	return subTreePtr; 
// 	} // end if
// }

// template<class T>
// int Translator<T>::getHeightHelper(BstNode<T>* subTreePtr) const {
// 	if (subTreePtr == nullptr) {
// 		return 0;
// 	}else{
// 		return 1 + max(getHeightHelper(subTreePtr->getLeft()), getHeightHelper(subTreePtr->getRight())); 
// 	}
// }

// template<class T>
// int Translator<T>::getHeight() const{
// 	return getHeightHelper(rootPtr);
// }
// template<class T>
// void Translator<T>::inorder(void visit(T&), BstNode<T>* treePtr) const{
// 	if (treePtr != nullptr) {
// 		inorder(visit, treePtr->getLeft()); 
// 		T theElement = treePtr->getElement(); 
// 		visit(theElement);
// 		inorder(visit, treePtr->getRight());
// 	} // end if
// }

// template<class T>
// void Translator<T>::inorderTraverse(void visit(T&)) const{
// 	inorder(visit, rootPtr);
// }