// empl_io.cpp
// performs file I/O on employee objects
// handles different sized objects
#include <fstream>
//for file-stream functions
#include <iostream>
#include <typeinfo>
//for typeid()
using namespace std;
#include <cstdlib>
//for exit()
const int LEN = 32;
const int MAXEM = 100;
//maximum length of last names
//maximum number of employees
enum employee_type {tmanager, tscientist, tlaborer};
////////////////////////////////////////////////////////////////////////
class employee {

	private:
		char name[LEN];
		unsigned long number; // employee number 
		static int n; 
		static employee* arrap[]; // array of ptrs to employees
	public:
		virtual void getdata(){
			cin.ignore(10,'\n');
			cout << " Enter last name: "; cin >> name;
			cout << " Enter Number: "; cin >> number;
		}
		virtual void putdata(){
			cout << "\n Name: " << name;
			cout << "\n Number: " << number;
		}
		virtual employee_type get_type(); // get type
		static void add(); // add employees
		static void display();  // display all employess 
		static void read(); // read from disk file
		static void write(); // write to disk file	
};
////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------
// static variables defintions 
int employee::n; // current number of employees 
employee* employee::arrap[MAXEM]; // array of ptrs to emps 
//----------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////
//manager class 
class manager : public employee{
	
	private:
		char title[LEN];
		double dues; 
	public:
		void getdata() {
			employee::getdata();
			cout << "	Enter title: "; cin >> title;
			cout << "	Enter golf club dues: "; cin >> dues;
		}
		void putdata() {
			employee::putdata();
			cout << "\n Title: " << title;
			cout << "\n Golf club dues: " << dues; 
		}
		
};
////////////////////////////////////////////////////////////////////////
// scientist class 
class scientist : public employee {
	private:
		int pubs;
	public:
		void getdata() {
			employee::getdata();
			cout << "	Enter number of pubs: "; cin >> pubs;
		}
		void putdata() {
			employee::putdata();
			cout << "\n  Number of publications: " << pubs;
		}	
};
////////////////////////////////////////////////////////////////////////
//laborer class 
class laborer : public employee {
	
	};
////////////////////////////////////////////////////////////////////////
// add employee to list  in memory
void employee::add() {
	char ch;
	cout << "'m' to add a manager" 
			"\n's' to add a scientist"
			"\n'l' to add a laborer"
			"\nEnter selection: ";
	cin >> ch;
	switch(ch) {
		case 'm': arrap[n] = new manager; break;
		case 's': arrap[n] = new scientist; break;
		case 'l': arrap[n] = new laborer; break; 
		default: cout << "\nUnknown employee type\n"; return;
	}
	arrap[n++]->getdata(); // get employee data from user 
}
//----------------------------------------------------------------------
// display all employees
void employee::display(){
	
	for (int i = 0; i<n ; i++){
		cout << (i+1);		
		switch( arrap[i]->get_type() ) {// display type
			case tmanager: cout << ". Type: Manager"; break;
			case tscientist: cout << ". Type: scientist"; break;
			case tlaborer: cout << ". Type: Laborer"; break;
			default: cout << ". Unknown Type"; break;
		}
	arrap[i]->putdata(); // display employee data 
	cout << endl; 
	}
}
//----------------------------------------------------------------------
//return the type of this object
employee_type employee::get_type() {
	
	if( typeid(*this) == typeid(manager) )
		return tmanager;
	else if (typeid(*this) == typeid(scientist) )
		return tscientist;
	else if (typeid(*this) == typeid(laborer) )
		return tlaborer;
	else {
		cerr << "\nBad employee type "; exit(1); }
	return tmanager;
}
//----------------------------------------------------------------------
//write all current memory objects to file
void employee::write() {
	
	int size;
	cout << "Writing " << n << " employees. \n";
	ofstream ouf; 
	employee_type e_type; 
	
	ouf.open("EMPLOY.DAT",ios::binary| ios::trunc);
	if(!ouf) {
		cout << "\nCan't open file\n"; return; }
		
	for( int i=0; i<n ; i++ ) {
		e_type = arrap[i]->get_type();
		ouf.write( (char*)&e_type, sizeof(e_type) );
		switch(e_type) {
			case tmanager:  size = sizeof(manager); break;
			case tscientist: size = sizeof(manager); break;
			case tlaborer:   size = sizeof(manager); break; 
			}
		ouf.write( (char*)(arrap[i]),size );
		if(!ouf) {
			cout << "\nCan't write to file\n"; return; 
			}
		}			
}
//----------------------------------------------------------------------
// read data for all employees from file into memory
void employee::read() {
	
	int size; 
	employee_type e_type;
	ifstream inf;
	inf.open("EMPLOY.DAT", ios::binary);
	if(!inf) {
		cout << "\nCan't open file\n"; return; }
	n = 0; 
	while(true) { 
		inf.read( (char*)&e_type, sizeof(e_type) );
		if( inf.eof() )
			break;
		if(!inf) {
			cout << "\nCan't read type from file\n"; return; }
		switch(e_type) {
			case tmanager: 
				arrap[n] = new manager; 
				size = sizeof(manager);
				break;
			case tscientist:
				arrap[n] = new scientist;
				size = sizeof(scientist);
				break;
			case tlaborer:
				arrap[n] = new laborer;
				size = sizeof(laborer);
				break;
			default: cout << "\nUnkown type in file\n"; return; 
		}
		inf.read( (char*)arrap[n],size );
		if(!inf){
			cout << "\nCan't read data from file\n"; return; }
		n++;
	} //end while
	cout << "Reading " << n << " employees\n";
}
////////////////////////////////////////////////////////////////////////
int main() {
	
	char ch;
	while(true) {
		cout << "'a' -- add data for an employee"
				"\n'd' -- display data for all employees"
				"\n'w' -- write all employees"
				"\n'r' -- read all employees data from file"
				"\n'x' -- exit"
				"\nEnter selection: ";
		cin >> ch;
		switch(ch) {
			case 'a':
				employee::add(); break;
			case 'd':
				employee::display(); break;
			case 'w':
				employee::write(); break;
			case 'r':
				employee::read(); break;
			case 'x': exit(0);
			}
		} // end while 
	return 0;
}
			
				
			
	
