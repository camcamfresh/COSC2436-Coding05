/*
 * Put your comment header here
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
