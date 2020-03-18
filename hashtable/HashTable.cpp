#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "HashTable.h"

using namespace std;

int HashTable::hash(string key)
{
	int sum=0;
	for(int i=1;i<key.length();i++)
		sum=sum*10+(key[i]-48);
	return (sum%SIZE);
}

void HashTable::addItem(string key, string gender, int height, int weight)
{
	item it(key,gender,height,weight);
	table[hash(key)].push_front(it);
}

item &HashTable::operator[](string key)
{
	int h=hash(key);
	list<item>::iterator i=table[h].begin();
	for(;i!=table[h].end();i++)
	{
		if(i->key==key)
		{
			break;
		}
	}
	return *i;
}
