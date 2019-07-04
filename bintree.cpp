/* Name: Cameron Salazar
 * Assignment: Coding05 - Binary Search Tree
 * Data: July 4, 2019
 * Purpose: This assignment explores a basic binary search tree that does not include balancing; main.cpp test the class BinTree from bintree.cpp. Many methods have wrappers bintree.cpp for recursion, except addNode, getNode and removeNode which are longer as a result (however may operate faster with larger data sets).
 * Note: The parameters for the method getNode have been reversed from (Data *, id) to (id, Data *), with permission. As a result, calls to getNode in main.cpp had to be altered. This allows the contains method to use getNode.
*/ 

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
	if(root) *output = *root; //structure slicing
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

//This method is longer since it does not use recursion. This is beneficial for large data trees.
//This method was super difficult, so there will be extra comments in case I revisit this data structure.
bool BinTree::removeNode(int id){
	//Find what we want to delete and set it equal to target. If a parent exist set it, if not parent will remain NULL.
	//If there is no parent (i.e. root == target) then we know we are working on the root node.
	DataNode * parent = NULL, * target = root;
	while(target && target->id != id){
		parent = target;
		target = target->id > id ? target->left : target->right;
	}
	
	//If we found what we want to delete, make cases depending on the target's children (wow that sounds bad).
	if(target && target->id == id){
		if(target->left && target->right){ //most difficult case
			//we are not going to delete the target; instead we will replace it's data with the minimum node of the target's right branch (not necessiarly its right child).
			//the minimum node in the target's right branch will be greater than all nodes in the target's left branch by definition of a binary search tree.
			//once replaced, we delete the minimum node ensuring that there are no dangling pointers in the minimum node's parent; the minimum node should be a leaf.
			DataNode * minParent = target, * min = target->right;
			while(min->left){
				minParent = min;
				min = min->left;
			}
			
			target->id = min->id;
			target->information = min->information;
			if(minParent == root) root->right = NULL;
			else minParent->left == min ? minParent->left = NULL : minParent->right = NULL;
			delete min;
		}
		else if(target->left){ //target has one child; replace root pointer if no parent, else replace parent pointer
			if(!parent) root = target->left;
			else parent->left == target ? parent->left = target->left : parent->right = target->left;
			delete target;
		}			
		else if(target->right){
			if(!parent) root = target->right;
			else parent->left == target ? parent->left = target->right : parent->right = target->right;
			delete target;
		}			
		else{//easiest; delete makeing sure there are no dangling pointers in the parent.
			if(!parent) root = NULL;
			else parent->left == target ? parent->left = NULL : parent->right = NULL;
			delete target;
		}
		size--;
		return true;
	}
	else return false;
}

//This method is longer since it does not use recursion and contains the work for contains().
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