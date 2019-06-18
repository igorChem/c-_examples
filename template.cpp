// template.cpp
// template example 
#include <iostream>
#include <string>

using namespace std; 


template<class T>
int TemplatedSwap(T& a, T& b)
{
	T temp = a;
	a = b; 
	b=temp; 
	return 0;	
}

int main()
{
  int a = 5;
  int b = 10;
  //Swap(a,b);
  string firstName("Vitthal");
  string lastName("Srinivasan");

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Testing the int swap ~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  cout << "Before the swap, inside main " 
       << "a = " << a
       <<" b = " << b
       << endl;
       
  TemplatedSwap(a,b);
  
  cout << "After the swap, inside main " 
       << "a = " << a
       <<" b = " << b
       << endl;

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Testing the string swap ~~~~~~~~~~~~~~~~~~~~~~~" << endl;


  cout << "Before the swap, inside main " 
       << "a = " << firstName
       <<" b = " << lastName
       << endl;

	TemplatedSwap(firstName,lastName);
	
	cout << "After the swap, inside main " 
       << "a = " << firstName
       <<" b = " << lastName
       << endl;
	
}
