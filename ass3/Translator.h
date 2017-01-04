/*
 * File:              Translator.h
 *
 * Class Description: header for the data collection ADT called Translator
 *
 * Author:            Emadur Rahman
 * Student number :   301222147 
 *
 * Date:              July 2016
 *
 */
#pragma once
#include "BstNode.h"
#include "EtoK.h"

template<class T>
class Translator{
private: 
	BstNode<T>* rootPtr;
	void destroyTree(BstNode<T>* subTreePtr);
	BstNode<T>* copyTree(BstNode<T>* treePtr) const; //used for copy constructor
	BstNode<T>* insertInorder(BstNode<T>* subTreePtr, BstNode<T>* newNodePtr);
	void printInOrderPrivate(BstNode<T>* subTreePtr);
	void findNodePrivate(BstNode<T>* subTreePtr, string str);


	//For Testing: ignore
	//int getHeightHelper(BstNode<T>* subTreePtr) const;
	//BstNode<T>* balancedAdd(BstNode<T>* subTreePtr, BstNode<T>* newNodePtr);
	
	//void inorder(void visit(T&), BstNode<T>* treePtr) const;
public:
	//constructors and destructor
	Translator();
	Translator(const T& rootItem);
	Translator(const T& rootItem, const Translator<T>* leftTreePtr, const Translator<T>* rightTreePtr);
	Translator(const Translator<T>& tree);
	virtual ~Translator();

	bool add(const T& newData);
	T getRootData() const; //getter
	void printInOrder();
	void findNode(string str);


	//For Testing: ignore
	//int getHeight() const;
	//void inorderTraverse(void visit(T&)) const;
};