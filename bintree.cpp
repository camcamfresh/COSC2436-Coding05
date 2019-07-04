#include "bintree.h"
	
BinTree::BinTree(){
	root = NULL;
	size = 0;
}

BinTree::~BinTree(){
	clear();
}
	
bool BinTree::isEmpty(){
	return size == 0;
}

int BinTree::getCount(){
	return size;
}

bool BinTree::getRootData(Data *){
	if(root) *output = *root; //object slicing
	else{
		output->id = -1;
		output->information = "";
	}
	return root;
}

void BinTree::clear(){
	
}
bool BinTree::addNode(int, string){
	return false;
}
bool BinTree::removeNode(int){
	return false;
}
bool BinTree::getNode(int, Data *){
	return false;
}
bool BinTree::contains(int){
	return false;
}
bool BinTree::getHeight(){
	return false;
}
	
void BinTree::displayPreOrder(){
	
}
void BinTree::displayPostOrder(){
	
}
void BinTree::displayInOrder(){
	
}
void BinTree::displayTree(){
	
}