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
	bool removeNode(DataNode *, DataNode * = NULL);
	DataNode * findMin(DataNode *);
	
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