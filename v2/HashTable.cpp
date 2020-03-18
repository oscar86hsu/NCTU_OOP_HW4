#include "HashTable.h"
#include <string>
#include <iostream>
using namespace std;
HashTable::HashTable()
{
	size_of_HashTable=0;
}

HashTable::~HashTable()
{

}
int HashTable::hash(string key)
{
	int value=0;
	for(int i=0;i<key.length();i++)
	{
		value+=key[i];
	}
	return (value%SIZE);
}
void HashTable::addItem(string key,string gender,int height,int weight)
{
	item *it=new item;
	it->key=key;
	it->gender=gender;
	it->height=height;
	it->weight=weight;
	it->next=NULL;
	LL[hash(key)].insert(it);
}

item &HashTable::operator[](string key)
{
	return LL[hash(key)][key];
}

//**********************************************************************************//
LinkList::LinkList()
{
	head=NULL;
	tail=NULL;
	size_of_LinkList=0;
}
LinkList::~LinkList()
{

}
item &LinkList::operator[](string key)
{
	item *tmp=head;
	while(head)
	{
		if(tmp->key==key)
			break;
		else
			tmp=tmp->next;
	}
	return *tmp;
}

void LinkList::insert(item *it)
{
	if(head)
	{
		tail->next=it;
		tail=it;
	}
	else
	{
		head=it;
		tail=it;
	}
}
//**********************************************************************************//

string item::getGender()
{
	return gender;
}
int item::getHeight()
{
	return height;
}
int item::getWeight()
{
	return weight;
}











