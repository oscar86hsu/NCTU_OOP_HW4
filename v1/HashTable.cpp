#include "HashTable.h"
#include <string>
#include <iostream>
using namespace std;
HashTable::HashTable()
{
	head=NULL;
	tail=NULL;
	size_of_HashTable=0;
}

HashTable::~HashTable()
{

}

void HashTable::addItem(string key,string gender,int height,int weight)
{
	item *it=new item;
	it->key=key;
	it->gender=gender;
	it->height=height;
	it->weight=weight;
	it->next=NULL;
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
	size_of_HashTable++;
}

item &HashTable::operator[](string key)
{
	item *tmp=head;
	while(tmp)
	{
		if(tmp->key==key)
			break;
		else
			tmp=tmp->next;
	}
	return *tmp;
}



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











