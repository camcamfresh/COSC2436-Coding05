/* Name: Cameron Salazar
 * Assignment: Coding05 - Binary Search Tree
 * Data: July 4, 2019
 * Purpose: This assignment explores a basic binary search tree that does not include balancing; main.cpp test the class BinTree from bintree.cpp. Many methods have wrappers bintree.cpp for recursion, except addNode, getNode and removeNode which are longer as a result (however may operate faster with larger data sets).
 * Note: The parameters for the method getNode have been reversed from (Data *, id) to (id, Data *), with permission. As a result, calls to getNode in main.cpp had to be altered. This allows the contains method to use getNode.
*/ 

#ifndef BINTREE_H
#define BINTREE_H

#include "data.h"
#include <iostream>

class BinTree{
private:
	DataNode * root;
	int size;

	void clear(DataNode *);
	int getHeight(DataNode *, int = 0);
	
	void displayPreOrder(DataNode *);
	void displayPostOrder(DataNode *);
	void displayInOrder(DataNode *);
public:
	BinTree();
	~BinTree();
	
	bool isEmpty();
	int getCount();
	bool getRootData(Data *);
	void clear();
	bool addNode(int, string);
	bool removeNode(int);
	bool getNode(int, Data * = NULL);
	bool contains(int);
	int getHeight();
	
	void displayPreOrder();
	void displayPostOrder();
	void displayInOrder();
	void displayTree();
};

#endif