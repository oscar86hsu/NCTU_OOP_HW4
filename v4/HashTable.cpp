#include <iostream>
#include <string>
#include <unordered_map>
#include "HashTable.h"
using namespace std;

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

void HashTable::addItem(string key,string gender,int height,int weight)
{
	item *it=new item;
	it->gender=gender;
	it->height=height;
	it->weight=weight;
	my_map.insert(pair<string,item>(key,*it));
}

item &HashTable::operator[](string key)
{
	return my_map[key];
}