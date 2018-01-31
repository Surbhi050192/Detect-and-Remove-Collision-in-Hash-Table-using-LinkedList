// Name: Surbhi Goel
// Loginid: surbhigo
// CS 455 PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {

	Node* list = NULL;
	
	listInsert(list,"Monica", 10);//inserts at last
	listPrint(list);
	listInsert(list,"Pheebi", 10);
	cout<<"number of entries are "<<listEntries(list)<<endl;
	listPrint(list);
	listInsert(list,"Joey", 20);
	listInsert(list,"Chandler", 20);
	listChange(list,"Joey",0);
	listFind(list,"Chandler");
	listRemove(list,"Pheebi");
	cout<<"number of entries are "<<listEntries(list)<<endl;
	listFind(list,"Pheebi");
	listPrint(list);

  return 0;
}
