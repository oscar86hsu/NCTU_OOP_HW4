#ifndef HASHTABLE
#define HASHTABLE
#include <string>
#include "HashTable.h"
#define SIZE 9973
using namespace std;

class item
{
public:
    string gender;
    int height;
    int weight;
    item();
    ~item();
    string key;
    item *right;
    item *left;
    string getGender();
    int getHeight();
    int getWeight();
};
class Bin_Tree
{
private:
    item *root;
public:
    Bin_Tree();
    int Bin_Hash(string key);
    void insert(item *it);
    item &operator[](string key);
};
class HashTable
{
private:
	Bin_Tree BT[SIZE];
	int size_of_HashTable;
public:
	HashTable();
	~HashTable();
    int hash(string key);
	void addItem(string key,string gender,int height,int weight);
	item &operator[](string key);
};


#endif
