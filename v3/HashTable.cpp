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
	for(int i=1;i<key.length();i++)
	{
		value=value*10+key[i];
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
	BT[hash(key)].insert(it);
}

item &HashTable::operator[](string key)
{
	return BT[hash(key)][key];
}

//**********************************************************************************//
Bin_Tree::Bin_Tree()
{
	root=NULL;
}

int Bin_Tree::Bin_Hash(string key)
{
	return (int)(key[key.length()-1]+key[key.length()-2]);
}

void Bin_Tree::insert(item *it)
{
	if(root==NULL)
	{
		root=it;
		return;
	}
	else
	{
		int h=Bin_Hash(it->key);
		item *r=root;
		while(1)
		{
			if(h>Bin_Hash(r->key))
			{
				if(r->right==NULL)
				{
					r->right=it;
					return;
				}
				else
					r=r->right;
			}
			else
			{
				if(r->left==NULL)
				{
					r->left=it;
					return;
				}
				else
					r=r->left;
			}
		}
		
	}
}

item &Bin_Tree::operator[](string key)
{
	int h=Bin_Hash(key);
	item *r=root;
	while(1)
	{
		if(h>Bin_Hash(r->key))
		{
			r=r->right;
		}
		else
		{
			if(r->key==key)
				return *r;
			else
				r=r->left;
		}
	}


}
//**********************************************************************************//
item::item()
{
	right=NULL;
	left=NULL;
}
item::~item()
{

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











