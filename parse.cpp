// parse.cpp
// evaluates arithmetic expressions composed of 1-digit numbers
#include <iostream>
#include <cstring>  //for strlen(), etc
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;
const int LEN = 80; //length of expressions, in characters
const int MAX = 40; //size of stack

///////////////////////////////////////////////////////////////////////

class Stack
{
	private:
		char st[MAX];
		int top;
	public:
		Stack()
			{top=0;}
		void push(char var) // put a char on the stack
			{st[++top] = var;}
		char pop()          // take a char off the stack
			{return st[top--];} 
		int gettop()		// get top stack
			{return top;} 
};

/////////////////////////////////////////////////////

class express
{
	private:
		Stack s;
		char* pStr;  //pointer to a input string 
		int len;
	public:
		express(char* ptr) // constructor
		{
			pStr = ptr;    // set pointer to string
			len  = strlen(pStr);
		}
	void parse(); //parse the input string
	int solve();  //evaluate the stack
};
//---------------------------------------------------
void express::parse() //add item to stack 
{
	char ch; 
	char lastval; 
	char lastop;
	
	for(int i=0; i<len;i++) // loop through len of string in input
	{
		ch=pStr[i];
		
		if(ch>='0' && ch <='9')
			s.push(ch-'0');
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			if(s.gettop()==1)
			s.push(ch);
			else
			{
				lastval = s.pop(); 
				lastop = s.pop(); 
				if( (ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
				{
					s.push(lastop);
					s.push(lastval);
				}
				else
				{
					switch(lastop)
					{
						case '+': s.push(s.pop() + lastval); break;
						case '-': s.push(s.pop() - lastval); break;
						case '*': s.push(s.pop() * lastval); break;
						case '/': s.push(s.pop() / lastval); break;
						default: cout << "\nUnknown oper"; exit(1);
					}
				}
			s.push(ch);
			}
		}
	else
		{cout << "\nUnknow inpt character" << endl; exit(1);}
	
	}	
}
//---------------------------------------------------
int express::solve()
{
	char lastval;
	
	while(s.gettop()>1)
	{
		lastval = s.pop();
		switch( s.pop())
		{
			case '+': s.push(s.pop() + lastval); break;
			case '-': s.push(s.pop() - lastval); break;
			case '*': s.push(s.pop() * lastval); break;
			case '/': s.push(s.pop() / lastval); break;
			default: cout << "\nUnknow inpt character" << endl; exit(1);
		}
	return int(s.pop());
	}
}
//---------------------------------------------------
int main()
{
	char ans;
	char string[LEN];
	
	cout <<  "\nEnter an arithmetic expression"
			 "\nof the form 2+3*4/3-2."
			 "\nNo number may have more than one digit."
			 "\nDon’t use any spaces or parentheses.";
	do {
		cout << "\nEnter expression: ";
		cin >> string;
		express* eptr = new express(string); 
		eptr->parse();
		cout << "\nThe numerical value is: "
			<< eptr->solve();
		delete eptr;
		cout << "\nDo another (Enter y or n)?";
		cin >> ans;
	} while (ans =='y');
	return 0;
}

