#ifndef HASHTABLE
#define HASHTABLE
#include <string>
#define SIZE 500
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
class LinkList
{
private:
    int size_of_LinkList;
    item *head, *tail;
public:
    LinkList();
    ~LinkList();
    item &operator[](string key);
    void insert(item *it);
    
};
class HashTable
{
private:
	LinkList LL[SIZE];
	int size_of_HashTable;
public:
	HashTable();
	~HashTable();
    int hash(string key);
	void addItem(string key,string gender,int height,int weight);
	item &operator[](string key);
};


#endif
