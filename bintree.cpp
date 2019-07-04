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

bool BinTree::getRootData(Data * output){
	if(root) *output = *root; //object slicing
	else{
		output->id = -1;
		output->information = "";
	}
	return root;
}

void BinTree::clear(){
	clear(root);
	root = NULL;
	size = 0;
}
void BinTree::clear(DataNode * actingRoot){
	if(actingRoot->left) clear(actingRoot->left);
	if(actingRoot->right) clear(actingRoot->right);
	delete actingRoot;
}

bool BinTree::addNode(int id, string info){
	DataNode * parent, * search = root;
	while(search){
		if(id == search->id) return false;
		parent = search;
		search = id < search->id ? search->left : search->right;
	}
	
	DataNode * holder = new DataNode;
	holder->id = id;
	holder->information = info;
	holder->left = holder->right = NULL;
		
	if(root) id < parent->id ? parent->left = holder : parent->right = holder;
	else root = holder;
	
	size++;
	return true;
}

bool BinTree::removeNode(int){
	return false;
}

//This method is longer since it does not use recursion and contains the work for contains()
bool BinTree::getNode(int id, Data * output){
	if(root){
		DataNode * search = root;
		while(search){
			if(search->id == id){
				if(output) *output = *search;
				return true;
			}
			search = search->id > id ? search->left : search->right;
		}
	}
	if(output){
		output->id = -1;
		output->information = "";
	}
	return false;
}

bool BinTree::contains(int id){
	return getNode(id);
}

int BinTree::getHeight(){
	return getHeight(root) + 1;
}

int BinTree::getHeight(DataNode * actingRoot, int height){
	if(actingRoot){
		int lheight = 0, rheight = 0;
		if(actingRoot->left) lheight = getHeight(actingRoot->left, height) + 1;
		if(actingRoot->right) rheight = getHeight(actingRoot->right, height) + 1;
		height = lheight < rheight ? rheight : lheight;
		
	}
	return height;
}
	
void BinTree::displayPreOrder(){
	
}
void BinTree::displayPostOrder(){
	
}
void BinTree::displayInOrder(){
	
}
void BinTree::displayTree(){
	
}