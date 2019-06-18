// persort.cpp
// sorts person objects using array of pointers
#include <iostream>
#include <string>
 //for string class
using namespace std;

class person
{
	protected:
		string name;
	public:
		void setName()
			{cout <<"Enter name: ";cin >> name;}
		void printName()
			{cout << endl << name;}
		const string getName()
			{return name;}	
};
/////////////////////////////////////////////////////
int main()
{
	void bsort(person**, int);
	person* persPtr[100]; //array of pointers to persons
	int n = 0; // number of persons objects
	char choice; // input choice to possibly stop the program
	
	do {
		persPtr[n] = new person; // make new pointer to object in the array element n
		persPtr[n]->setName(); // get the name of the person object in the n element of array
		n++;
		cout << "Enter another (y/n)? ";
		cin >> choice;
		}
	while(choice == 'y');
	cout << "\nUnsorted list:";
	for(int i=0; i<n;i++)
		{persPtr[i]->printName();}
	
	bsort(persPtr,n); // sort pointers from a arrays of pointers of person objects
	
	cout << "\nSorted list:";
	for(int i=0; i<n;i++)
		{persPtr[i]->printName();}
	cout << endl;
	return 0;
	
}
//---------------------------------------------------
void bsort(person** pp, int n)
	{
		void order(person**,person**);
		int i,j;
		
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				order(pp+i,pp+j);
	
	}
//---------------------------------------------------
void order(person** pp1, person** pp2) 
	{
	if( (*pp1)->getName() > (*pp2)->getName())
		{
			person* tempptr = *pp1;
			*pp1 = *pp2;
			*pp2 = tempptr;
		}	
	}
