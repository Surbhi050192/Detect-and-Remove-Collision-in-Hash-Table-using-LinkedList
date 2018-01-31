// Name: Surbhi Goel
// Loginid: surbhigo
// CSCI 455 PA5
// Fall 2016

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"
#include<string>
// cstdlib needed for call to atoi
#include <cstdlib>
#include <locale>         // std::locale, std::tolower
int spaceCommand (string inputCommand)
{
	int i;
	int spaceCount=0;
	
	  for(i=0;i<inputCommand.size();i++)
	{
		if(inputCommand[i]==' ')
		{
			spaceCount++;
		}
	}
	
return spaceCount;
}
void help()
{
	cout<<"'insert name score' -> Insert this name and score in the grade table."<<endl;
	cout<<"'change name newscore' -> Change the score for name"<<endl;
	cout<<"'lookup name' -> Print out his or her score"<<endl;
	cout<<"'remove name' -> Remove this student"<<endl;
	cout<<"'print' -> Print all the entries"<<endl;
	cout<<"'size' -> Prints out the number of entries"<<endl;
	cout<<"'stats' -> Prints out statistics about the hash table at this point"<<endl;
	cout<<"'help' -> Prints out a brief command summary"<<endl;
	cout<<"'quit' -> Exits the program"<<endl;
}

int performCommands(Table* &mygrades,string command,string name,int score)
{//object pointer passed by reference
	if(command=="insert")
	{
		mygrades->insert(name,score);
	}

	else if(command=="change")
	{
		mygrades->change(name,score);
	}

	else if(command=="lookup")
	{
		mygrades->lookup(name);
	}
	
	else if(command=="remove")
	{
		mygrades->remove(name);
	}

	else if(command=="print")
	{
		mygrades->printAll();
	}
	
	else if(command=="size")
	{
		cout<<mygrades->numEntries()<<endl;
	}
	
	else if(command=="stats")
	{
		mygrades->hashStats(cout);
	}

	else if(command=="help")
	{
		help();
	}
	
	else if(command=="quit")
	{
		return 1;
	}

	else
	{
		help();
	}
	return 0;
}

int stringToInt( const char * str )
{
    int i = 0;
    while( *str ) 
	{
		i = i*10 + (*str++ - '0');
    }
    return i;
}

int main(int argc, char * argv[]) {

  string inputCommand;
  string word1,word2;
  int word3=0;
  int spaceCount=0;
  int firstSpace,secondSpace;
  int exitOrNot;
  // gets the hash table size from the command line
  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number" 
	   << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }
  
  while(1)
  {
	getline(cin,inputCommand);
	spaceCount=spaceCommand(inputCommand);

	if(spaceCount==2)//3 word command
	{	//word1
		firstSpace=inputCommand.find(" ");
		word1=inputCommand.substr(0,firstSpace);
		
		//second word2
		inputCommand=inputCommand.substr(firstSpace+1);
		secondSpace=inputCommand.find(" ");
		word2=inputCommand.substr(0,secondSpace);
		//word3
		inputCommand=inputCommand.substr(secondSpace+1);

		
		char *charStr = new char[inputCommand.length() + 1];
		strcpy(charStr, inputCommand.c_str());
		// do stuff
		
		word3 = stringToInt(charStr);
		delete [] charStr;
		////cout<<word3;
	}

	if(spaceCount==1)//2 word command
	{	//word1
		firstSpace=inputCommand.find(" ");
		word1=inputCommand.substr(0,firstSpace);
		//second word2
		inputCommand=inputCommand.substr(firstSpace+1);
		word2=inputCommand;
		
	}
	if(spaceCount==0)
	{
		word1=inputCommand;
	}

	//tolower
	std::locale loc;
	for (string::size_type i=0; i<word1.length(); ++i)
    word1[i] = std::tolower(word1[i],loc);

	for (string::size_type i=0; i<word2.length(); ++i)
    word2[i] = std::tolower(word2[i],loc);

	exitOrNot=performCommands(grades,word1,word2,word3);
	if(exitOrNot==1)
	{
		break;
	}
  }
  return 0;
}
