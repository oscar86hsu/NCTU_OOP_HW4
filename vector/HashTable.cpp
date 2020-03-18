#ifndef HASHTABLE_CPP 
#define HASHTABLE_CPP

#include "HashTable.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;
//using std::vector;
//using std::string;


int HashTable::PreHashing(string key_str)
{
    int key_int=0;
	for(int i=1; i<(int)key_str.size(); i++)
	{
		key_int = key_int*10+(key_str[i]-48);
	}
	return key_int;
}

int HashTable::HashFunction(string key_str)
{
	int key_index=PreHashing(key_str);
	return (key_index%size);
}
//
void HashTable::addItem(string Key_str, string Gender_str, int Height_int, int Weight_int)
{
	status_items entry(Key_str, Gender_str, Height_int, Weight_int);
	//entry.Key=Key_str;
	//entry.Gender=Gender_str;
	//entry.Height=Height_int;
	//entry.Weight=Weight_int;
	int index=HashFunction(Key_str);
	(table[index]).push_front(entry);	//() in (table.[index]) is requisite
}
//
status_items &HashTable::operator[](string key_str)	
{
	int index=HashFunction(key_str);
	for (list<status_items>::iterator itr=table[index].begin(); itr !=table[index].end(); itr++)
	{
		if((*itr).Key==key_str)
		{
			return (*itr);
		}			
	}
	return (*this).items;
}
//
string status_items::getGender()
{
	return (*this).Gender;
}
//
int status_items::getHeight()
{
	return (*this).Height;
}

int status_items::getWeight()
{
	return (*this).Weight;
}
// 
#endif //HASHTABLE_CPP

