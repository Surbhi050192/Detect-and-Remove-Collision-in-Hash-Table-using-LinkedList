// Name: Surbhi Goel
// Loginid: surbhigo
// CSCI 455 PA5
// Fall 2016


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType; // Hashtable[tablesize]

bool listInsert(ListType & list,const string &theKey, int theValue);//inserts at last

bool listChange(ListType & list, string target, int source);

int* listFind(ListType & list, string target);

bool listRemove(ListType & list, string target);

void listPrint(ListType & list);

int listEntries(ListType & list);
//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.













// keep the following line at the end of the file
#endif
