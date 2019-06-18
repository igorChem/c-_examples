//constkeyword1.cpp
// demonstrate the use of cons keyword
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char firstname[] = "vithal";
	char lastname[] = "srinivasan";
	
	char *p1 = firstname; // non-const pointer, non-const data
	
	p1[0] = 'z';
	
	p1 = lastname;	
	
	const char *p2 = firstname; // non-const pointer,const data
	
	//p2[0]= 'z' ; can't update 
	
	p2 = lastname;	
	
	char* const p3 =firstname;
	cout << "Initial Value of p3 : " << p3 << endl;
    p3[0] = 'Z';                         // can change the data
    cout <<  "Value of p3 after changing data : " << p3 << endl;
    p3 = lastname; // can NOT change what is pointed to
    cout <<  "Value of p3 after changing what it points to : " << p3 << endl;
	return 0; 
}
