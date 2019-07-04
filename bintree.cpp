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

bool BinTree::removeNode(int id){
	DataNode * parent = NULL, * search = root;
	while(search && search->id != id){
		parent = search;
		search = id < search->id ? search->left : search->right;
	}
	if(search == NULL) return false; //id not found.
	if(search->left && search->right){
		DataNode * minParent = root, * min = search->right;
		while(min->left){
			minParent = min;
			min = min->left;
		}
		search->id = min->id;
		search->information = min->information;
		removeNode(min, minParent);
	}
	else removeNode(search, parent);
	return true;
}

bool BinTree::removeNode(DataNode * target, DataNode * parent){
	if(target->left){
		if(parent) parent->left == target ? parent->left = target->left : parent->right = target->left;
		else root = target->left;
	}
	else if(target->right){
		if(parent) parent->right == target ? parent->right = target->right : parent->left = target->right;
		else root = target->right;
	}
	else if(parent) parent->left == target ? parent->left = NULL : parent->right = NULL;
	delete target;
	size--;
	return true;
}

DataNode * findMin(DataNode * actingRoot){
	while(actingRoot->left) actingRoot = actingRoot->left;
	return actingRoot;
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
	return root ? getHeight(root) + 1 : 0;
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
	if(root) displayPreOrder(root);
	std::cout << std::endl;
}

void BinTree::displayPreOrder(DataNode * actingRoot){
	std::cout << actingRoot->id << " " << actingRoot->information << std::endl;
	if(actingRoot->left) displayPreOrder(actingRoot->left);
	if(actingRoot->right) displayPreOrder(actingRoot->right);
}

void BinTree::displayPostOrder(){
	if(root) displayPostOrder(root);
	std::cout << std::endl;
}

void BinTree::displayPostOrder(DataNode * actingRoot){
	if(actingRoot->left) displayPostOrder(actingRoot->left);
	if(actingRoot->right) displayPostOrder(actingRoot->right);
	std::cout << actingRoot->id << " " << actingRoot->information << std::endl;
}

void BinTree::displayInOrder(){
	if(root) displayInOrder(root);
	std::cout << std::endl;
}

void BinTree::displayInOrder(DataNode * actingRoot){
	if(actingRoot->left) displayInOrder(actingRoot->left);
	std::cout << actingRoot->id << " " << actingRoot->information << std::endl;
	if(actingRoot->right) displayInOrder(actingRoot->right);
}

void BinTree::displayTree(){
	std::cout << "DISPLAY TREE\n==============================================" << std::endl;
	std::cout << "Tree is " << (isEmpty() ? "empty\n" : "not empty\n");
	std::cout << "Height " << getHeight() << std::endl;
	std::cout << "Node count: " << size << std::endl << std::endl;
	
	std::cout << "Pre-Order Transversal" << std::endl;
	displayPreOrder();
	
	std::cout << "In-Order Transversal" << std::endl;
	displayInOrder();
	
	std::cout << "Post-Order Transversal" << std::endl;
	displayPostOrder();
}