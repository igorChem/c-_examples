// rewobj.cpp
// person objects do disk I/O
#include <fstream>
//for file streams
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////
class person{ 

	protected:
		char name[80];
		//person’s name
		short age;
		//person’s age
	public:
		void getData(){
		cout << "\n	Enter name: "; cin >> name;
		cout << "Enter age: "; cin >> age;
		}
		void showData(){
			cout << "\n Name: " << name;
			cout << "\n Age: " << age;				
		}
		void diskIn(int); // read from file
		void diskOut(); // write to file 
						// person in file 
		static int diskCount();
};
//----------------------------------------------------------------------
void person::diskIn(int pn) { // read person number pn
	ifstream infile;
	infile.open("PERSFILE.DAT",ios::binary);
	infile.seekg( pn*sizeof(person) );
	infile.read( (char*)this,sizeof(this) ) ;	
	}
//----------------------------------------------------------------------
void person::diskOut() {
	ofstream outfile;
	outfile.open("PESFILE.DAT",ios::binary|ios::app);
	outfile.write( (char*)this,sizeof(*this) );
	}
//----------------------------------------------------------------------
int person::diskCount(){
	ifstream infile;
	infile.open("PESFILE.DAT",ios::binary);
	infile.seekg(0,ios::end); 
	
	return (int)infile.tellg()/sizeof(person);	
	}
////////////////////////////////////////////////////////////////////////
int main(){
	
	person p; 
	char ch; 
	
	do {
		cout << "Enter data for person:";
		p.getData();
		p.diskOut();
		cout << "Do another (y/n)?";
		cin >> ch; 
	}	while(ch == 'y');
	
	int n  = person::diskCount();
	cout << "There are " << n << " persons in file\n";
	for( int i = 0; i<n ; i++) {
		cout << "\nPerson " << i;
		p.diskIn(i);
		p.showData();		 
	}
	
	cout << endl;
		
	return 0;
}
