#ifndef BINTREE_H
#define BINTREE_H

#include "data.h"

class BinTree{
private:
	DataNode * root;
	int size;

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
	bool getHeight();
	
	void displayPreOrder();
	void displayPostOrder();
	void displayInOrder();
	void displayTree();
};

#endif