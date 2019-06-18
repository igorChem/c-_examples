// ptrobjs.cpp
// array of pointers to objects
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////

class person
{
	protected:
		char name[40];
	public:
		void setName()
		{
			cout << "Enter Name: "; cin >> name;
		}
		void printName()
		{
			cout << "\nName is: " << name;
		}
};
/////////////////////////////////////////////////////

int main()
{
	person* persPtr[100];
	int n = 0;
	char choice;
	
	do
		{
			persPtr[n] = new person;
			persPtr[n]->setName();
			n++;
			cout << "Enter another (y/n)?";
			cin >> choice;
		}
	while(choice == 'y');
	
	for(int i=0;i<n;i++)
	{
		cout << "\nPearson number" << i+1;
		persPtr[i]->printName();
	}
	return 0;
}
