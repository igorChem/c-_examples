// setpers.cpp
// uses a multiset to hold person objects
#include <iostream>
#include <set>
#include <string>
#include <iterator>
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
//----------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////
int main() {
	
	person pers1("Deauville", "William", 8435150);
	person pers2("McDonald",   "Stacey", 3327563);
	person pers3("Bartoski",    "Peter", 6946473);
	person pers4("KuangThu",    "Bruce", 4157300);	
	person pers5("Wellington",   "John", 9207404);
	person pers6("McDonald",   "Amanda", 8435150);
	person pers7("Fredericks",  "Roger", 7049982);
	person pers8("McDonald",   "Stacey", 7764987);
	
	multiset< person, less<person> > persSet;
	
	multiset< person,less<person> >::iterator iter;
	
	persSet.insert(pers1);
	persSet.insert(pers2);
	persSet.insert(pers3);
	persSet.insert(pers4);
	persSet.insert(pers5);
	persSet.insert(pers6);
	persSet.insert(pers7);
	persSet.insert(pers8);
	
	cout << "\nNumber of entries = " << persSet.size();
	
	iter = persSet.begin();
	while( iter != persSet.end() )
		(*iter++).display();
		
	string searchLastName, searchFirstName;
	cout << "\n\nEnter last name of person to search for: ";
	cin >> searchLastName;
	cout << "\n\nEnter first name of person to search for: ";
	cin >> searchFirstName;
	
	// creat a instance of entered person to comparsion with the set of persons 
	person searchPerson(searchLastName,searchFirstName,0);
	
	int cntPerson = persSet.count(searchPerson);
	cout << "Number of persons with this Name = " << cntPerson;
	
	iter = persSet.lower_bound(searchPerson);
	while( iter != persSet.upper_bound(searchPerson) )
		(*iter++).display();
	cout << endl;
	return 0;	
	}


