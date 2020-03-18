#ifndef HASHTABLE
#define HASHTABLE
#include <string>
using namespace std;

class item
{
public:
    string key;
    string gender;
    int height;
    int weight;
    item *next;
    string getGender();
    int getHeight();
    int getWeight();
};

class HashTable
{
private:
	item *head,*tail;
	int size_of_HashTable;
public:
	HashTable();
	~HashTable();
	void addItem(string key,string gender,int height,int weight);
	item &operator[](string key);
};

#endif
