#ifndef HASHTABLE 
#define HASHTABLE
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "HashTable.h"
#define SIZE 9973
using namespace std;

class item
{
public:
	item(string key, string gender, int height, int weight):key(key),gender(gender),height(height),weight(weight){}
	string key;
	string gender;
	int height;
	int weight;
	string getGender(){return gender;}
    int getHeight(){return height;}
    int getWeight(){return weight;}
};

class HashTable
{
private:
	vector<list<item> > table;
public:
	HashTable(){table.resize(SIZE);}		
	int hash(string key);
	void addItem(string key, string gender, int height, int weight);
	item &operator[](string key);
};
#endif