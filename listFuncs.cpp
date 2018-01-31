// Name: Surbhi Goel
// Loginid: surbhigo
// CSCI 455 PA5
// Fall 2016


#include <iostream>

#include <cassert>
#include <string>
#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}

bool listInsert(ListType & list,const string &theKey, int theValue)
{
	//call listFind to check whether the key isnt already there.
	//cout<<"Inserting......";

	Node * temp=list;
	Node * newNode= new Node(theKey,theValue);
	if(temp==NULL)//list points to head i.e. empty list
	{
		//cout<<"Key added"<<endl;
		list=newNode;//update head
		return 1;
	}
	else
	{
		

		while(temp != NULL)
		{
			if (temp->key.compare(theKey) == 0)
			{
				cout<<"Key already present, no addition"<<endl;
				return 0;
			}

			if(temp->next==NULL)
			{	temp->next=newNode;
				//cout<<"Key added to a specfic postion"<<endl;
				return 1;
			}
			temp = temp->next;
			
		}// go to the end
		
	

	}
	
	return 1;
}

int * listFind(ListType & list, string target)
{
	//cout<<"finding......";
	if(list==NULL)
	{	cout<<"Key Not Found "<<endl;
		return NULL;
	}
	Node * temp=list;
	while(temp != NULL) // not used temp->next since want to check the first element if list has only one Node
		{
			if (temp->key.compare(target) == 0)
			{	
				cout<<temp->key<<"  "<<temp->value<<endl;
				return &(temp->value);
			}
			temp = temp->next;
		}
	//else if not found
	cout<<"Key Not Found"<<endl;
	return NULL;
	
}

bool listChange(ListType & list, string target, int source)
{	
	//cout<<"Replacing......";
	if(list==NULL)
		{	cout<<"Key Not Found"<<endl;
			return 0;
		}
	Node * temp=list;
	while(temp!= NULL)
	{
		if (temp->key.compare(target) == 0)
		{
			//cout<<"found key whose value is :"<<list->value <<". ";
			temp->value=source;
			//cout<<"Replace succesful"<<endl;
			return 1;
		}
		temp = temp->next;
	}

	//else not found the key itself
	cout<<"Key Not found"<<endl;
	return 0;

	
}

bool listRemove(ListType & list, string target)
{
	//cout<<"Removing......";
	if(list==NULL)
		{	cout<<"Key Not Found"<<endl;
			return 0;
		}

	Node * temp=list;
	
	if(temp->next==NULL)//only one element
		{
			list=NULL;
			free(temp); 
			//cout<<"removal successful, removed "<<target<<". List is empty now"<<endl;
			return 1;
		}
	//more than one element
	while(temp->next != NULL) 
		{
			if(temp->key.compare(target) == 0) //removing first element will cause header to be change
			{
				//cout<<"going to remove. ";
				list=temp->next;
				free(temp);
				//cout<<"removal successful, removed "<<target<<endl;
				return 1;
			}
			if (temp->next->key.compare(target) == 0)// doesnt takes into account first elment
			{
				//cout<<"going to remove. ";
				
				
				//whhen its last element to be removed
				if(temp->next->next==NULL)
				{
					Node * dump=temp->next;
					temp->next=NULL;
					free(dump);
					//cout<<"removal successful, removed "<<target<<endl;
					return 1;
				}

				else//multiple elements
				{
					
					Node * dump=temp->next;
					temp->next=temp->next->next;
					free(dump);
					//cout<<"removal successful, removed "<<target<<endl;
					return 1;
				}
			}
			temp = temp->next;
		
		}

		
		//else not found the key itself
		cout<<"Key Not Found"<<endl;
		return 0;
}


void listPrint(ListType & list)
{

	//cout<<"Printing......"<<endl;
	if(list==NULL)
		{	//cout<<"empty list"<<endl;
			return;
		}

	Node * temp=list;
	while(temp != NULL)
		{
			cout<<temp->key<<" "<<temp->value<<endl;
			temp=temp->next;
		}

	
	
	return ;

}

int  listEntries(ListType & list)
{
	int count=0;
	
	if(list==NULL)
		{	
			return 0;
		}

	Node * temp=list;
	while(temp != NULL)
		{
			count=count+1;
			temp=temp->next;
		}
	return count;
}

//*************************************************************************
// put the function definitions for your list functions below
