// Name: Surbhi Goel
// Loginid: surbhigo
// CSCI 455 PA5
// Fall 2016

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */
#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
	hashSize=HASH_SIZE;//myedit -> hashsize the dividing mod factor to return hashcode

	////initailize first pointer for every bucket to 0
	
	data = new ListType [hashSize];
        for (int i = 0; i < hashSize; i++)
            data[i] = NULL;

}


Table::Table(unsigned int hSize) {
	hashSize=hSize;//myedit- > hashsize(private member in Table.h) the dividing mod factor to return hashcode

////initailize first pointer for every bucket to 0
	
	data = new ListType [hashSize];
        for (int i = 0; i < hashSize; i++)
            data[i] = NULL;
}

bool Table::insert(const string &key, int value) {
	
	
	Node *list = data[hashCode(key)];//first location of the bucket in table
	if(listInsert(list,key,value))
	{
		data[hashCode(key)]=list;//update head pointer of that list row
		return true;
	}
	//listInsert(ListType & list,const string &theKey, int theValue); list is the hashcode index
  return false;  // dummy return value for stub
}

bool Table::change(const string &key, int value) {
	
	
	Node *list = data[hashCode(key)];//first location of the bucket in table
	if(listChange(list,key,value))
	{
		
		return true;
	}
	
  return false;  // dummy return value for stub
}
int * Table::lookup(const string &key) {
	int *valueOfKey;

	Node *list = data[hashCode(key)];//first location of the bucket in table
	valueOfKey=listFind(list,key);
	return valueOfKey;   // dummy return value for stub
}

bool Table::remove(const string &key) {
	Node *list = data[hashCode(key)];//first location of the bucket in table
	if(listRemove(list,key))
	{
		data[hashCode(key)]=list;
		return true;
	}


  return false;  // dummy return value for stub
}


void Table::printAll() const {
	for (int i = 0; i < hashSize; i++)
           listPrint(data[i]);
}

int Table::numEntries() const {

	int TotaEntries=0;

	for (int i = 0; i < hashSize; i++)
	{
		//listEntries(ListType & list); //////return entires(count) in one list so added with previos result 
		TotaEntries=TotaEntries+listEntries(data[i]);
	}

  return TotaEntries;      // dummy return value for stub
}



void Table::hashStats(ostream &out) const {

	int filledBucketCount=0;
	int Max=0;
	int entry;
	out<<"number of buckets: "<<hashSize<<endl;
	out<<"number of entries: "<<numEntries()<<endl;
	out<<"number of non-empty buckets: ";
	for (int i = 0; i < hashSize; i++)
		{ if(data[i]!=0)
			{ filledBucketCount++;}
		}
	out<<filledBucketCount<<endl;

	out<<"longest chain: ";
	for(int i = 0; i < hashSize; i++)
		{
			entry=listEntries(data[i]);
			if(entry>Max)
			{
				Max=entry;
			}
		}
	out<<Max<<endl;

}


// add definitions for your private methods here
