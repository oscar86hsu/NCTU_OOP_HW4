#ifndef HASHTABLE
#define HASHTABLE
#include <iostream>
#include <string>
#include <unordered_map>
#include "HashTable.h"
using namespace std;

class item
{
public:
    string gender;
    int height;
    int weight;
    item(){}
    ~item(){}
    string getGender();
    int getHeight();
    int getWeight();
};

class HashTable
{
public:
	unordered_map<string,item> my_map;
	HashTable(){}
	~HashTable(){}
	void addItem(string key,string gender,int height,int weight);
	item &operator[](string key);
};

#endif
