#ifndef HASHTABLE 
#define HASHTABLE

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;
//using std::vector;
//using std::string;

struct status_items{		//works as class, but all members are public
//private:
	string Key;
	string Gender;
	int Height, Weight;
//public:
    status_items():Key(" "), Gender(" "), Height(0), Weight(0){}		//default constructor for node
    status_items(string Key_str, string Gender_str, int Height_int, int Weight_int)
	     :Key(Key_str), Gender(Gender_str), Height(Height_int), Weight(Weight_int){}	//copy constructor for giving the struct a value
//public:
    //friend class HashTable;		// if class status_items must declare as a friend class to let class HashTable use the class status_items
    string getGender();      		//return gender by item
    int getHeight();      			//return height by item
    int getWeight();     			//return weight by item	
};

class HashTable
{
	
private:
	int size;	//size of table
	
	status_items items;
	vector<list<status_items> > table;	//hash table with linked list implemented by list
	
	int PreHashing(string key_str);		//turn string-type key to int-type key
	int HashFunction(string key_str);	//using division method
	
public:
	HashTable():size(1024){		//initial constructor  
		table.resize(size);
	}
	~HashTable(){ }				//deconstructor
	
    void addItem(string Key_str, string Gender_str, int Height_int, int Weight_int); // add data into your hash table
    status_items &operator[](string key_str);	//return item by selected key
	
};

#endif //HASHTABLE

