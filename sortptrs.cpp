// sortptrs.cpp
// sorts person objects stored by pointer
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class person{
	
	private:
		string lastName;
		string firstName;
		long phoneNumber; 
	public: 
		person() : lastName("blank"), firstName("blank"), phoneNumber(0) {
		} // default constructor
		
		person(string lana, string fina, long pho): lastName(lana), 
		firstName(fina), phoneNumber(pho) {} // 3-arg constructor 
		
		friend bool operator<(const person&,const person&); // overloading operator
		friend bool operator==(const person&, const person&);
		
		void display() const // display object's data 
		{
			cout << endl << lastName << ",\t" << firstName
				 << "\t\tPhone: " << phoneNumber;				 
		}
				
		long get_phone() const // return phone number 
		{ return phoneNumber;}
};

//----------------------------------------------------------------------
bool operator<(const person& p1, const person& p2) {
	
	if(p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false; 
}
//----------------------------------------------------------------------
bool operator==(const person& p1, const person& p2) {
	return (p1.lastName == p2.lastName && 
			p1.firstName == p2.firstName ) ? true : false;	
}
////////////////////////////////////////////////////////////////////////
//function object to compare persons using pointers
class comparePersons {
	
	public:
		bool operator() (const person* ptrP1, const person* ptrP2) const 
			{return *ptrP1 < *ptrP2; }
	
};
////////////////////////////////////////////////////////////////////////
// function object to display a person, using a pointer
class displayPerson {
	
	public: 
		void operator() (const person* ptrP) const {
			ptrP->display();}
};
////////////////////////////////////////////////////////////////////////

int main() {
	
	vector<person*> vectPtrsPers; // a vector of ptrs to persons
	
	person* ptrP1 = new person("KuangThu", "Bruce", 4157300);
	person* ptrP2 = new person("Deauville ", "William", 8435150);
	person* ptrP3 = new person("Wellington", "John   ", 9207404);
	person* ptrP4 = new person("Bartoski  ", "Peter  ", 6946473);
	person* ptrP5 = new person("McDonald  ", "Stacey ", 7764987);
	person* ptrP6 = new person("Fredericks", "Roger  ", 7049982);
	
	vectPtrsPers.push_back(ptrP1);
	vectPtrsPers.push_back(ptrP2);
	vectPtrsPers.push_back(ptrP3);
	vectPtrsPers.push_back(ptrP4);
	vectPtrsPers.push_back(ptrP5);
	vectPtrsPers.push_back(ptrP6);
	
	for_each( vectPtrsPers.begin(),vectPtrsPers.end(),displayPerson() );
	
	sort( vectPtrsPers.begin(),vectPtrsPers.end(),comparePersons() );
	cout << "\n\nSorted person";
	for_each( vectPtrsPers.begin(),vectPtrsPers.end(),displayPerson() );
	
	while(!vectPtrsPers.empty() ) {
		delete vectPtrsPers.back(); // delete person 
		vectPtrsPers.pop_back(); // pop pointer
	}
	cout << endl;
	
	return 0;
}
	
