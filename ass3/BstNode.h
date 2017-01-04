/*
 * File:              BstNode.h
 *
 * Class Description: header for the node
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              July 2016
 *
 */
#pragma once
#include "EtoK.h"

template<class T>
class BstNode
{
private:
	T data;
	BstNode<T>* left;   //left child
	BstNode<T>* right;	//right child
public:	
	// Constructors
	BstNode();
	BstNode(const T& newElement);
	BstNode(const T& newElement, BstNode<T>* leftPtr, BstNode<T>* rightPtr);

	//setter and getter for data
	void setElement(const T& newElement);
	T getElement() const;

	bool isLeaf() const;
	
	//getters for left and right child
	BstNode<T>* getLeft() const;
	BstNode<T>* getRight() const; 

	//setters for left and right child
	void setLeft(BstNode<T>* leftPtr);
	void setRight(BstNode<T>* rightPtr);
};
