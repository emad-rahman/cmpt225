/*
 * File:              BstNode.cpp
 *
 * Class Description: implementation for the node
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              July 2016
 *
 */
#include "BstNode.h"

	//default constructor
	template<class T>	
	BstNode<T>::BstNode(){
		left = nullptr;
		right = nullptr;
	}// end default constructor


	//constructor 
	//Desription: sets the data to passed in parameter and 
	//				left and right child pointers to nullptr
	template<class T>
	BstNode<T>::BstNode(const T& newElement){
		data = newElement;
		left = nullptr;
		right = nullptr;
	}//end constructor


	//constructor
	//Description: sets data, left child, right child to the passed 
	//				in parameters
	template<class T>
	BstNode<T>::BstNode(const T& newElement, BstNode<T>* leftPtr, BstNode<T>* rightPtr){
		data = newElement;
		left = leftPtr;
		right = rightPtr;
	}


	//Description: setter, sets the element data
	template<class T>
	void BstNode<T>::setElement(const T& newElement){
		data = newElement;
	}


	//Description: getter, gets the element data
	template<class T>
	T BstNode<T>::getElement() const{
		return data;
	}


	//Description: checks if node is a pointer
	template<class T>
	bool BstNode<T>::isLeaf() const{
		if (left == nullptr && right == nullptr){
			return true;
		}
		return false;
	}
			

	//Description: getter, gets the left child node pointer
	template<class T>
	BstNode<T>* BstNode<T>::getLeft() const{
		return left;
	}
 

 	//Description: getter, gets the right child node pointer
	template<class T>
	BstNode<T>* BstNode<T>::getRight() const{
		return right;
	}


	//Description: setter, sets the left child pointer 
	template<class T>
	void BstNode<T>::setLeft(BstNode<T>* leftPtr){
		left = leftPtr;
	}


	//Description: setter, sets the right child pointer
	template<class T>
	void BstNode<T>::setRight(BstNode<T>* rightPtr){
		right = rightPtr;
	}

