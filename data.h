/* Name: Cameron Salazar
 * Assignment: Coding05 - Binary Search Tree
 * Data: July 4, 2019
 * Purpose: This assignment explores a basic binary search tree that does not include balancing; main.cpp test the class BinTree from bintree.cpp. Many methods have wrappers bintree.cpp for recursion, except addNode, getNode and removeNode which are longer as a result (however may operate faster with larger data sets).
 * Note: The parameters for the method getNode have been reversed from (Data *, id) to (id, Data *), with permission. As a result, calls to getNode in main.cpp had to be altered. This allows the contains method to use getNode.
*/ 

#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string information;
};

struct DataNode : Data {
    DataNode *left, *right;
};

#endif
