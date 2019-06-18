// maostl.cpp
// map exemple 

#include <iostream>
#include <vector> 
#include <map> 
using namespace std; 

class Person
{
private:
  string name;
public:
  Person(string s) : name(s)
  {
    cout << "In the 1-argument constructor" << endl; 
  }
  Person()
  {
    cout << "In the no-argument constructor" << endl; 
  }
  ~Person()
  {
    cout << "In the destructor" << endl;
  }
  string getName()
  {
    return name;
  }

};

int main()
{
	vector<Person> personVector(4);
	personVector[0] = Person("Janani");
	personVector[1] = Person("Swetha");
	personVector[2] = Person("Navdeep");
	personVector[3] = Person("Vitthal");


	personVector.push_back(Person("Ahmad"));
	personVector.push_back(Person("Pradeep"));
	personVector.push_back(Person("Anuradha"));

	cout<<personVector.capacity() << endl;
	cout<<personVector.size() << endl;

	for(int i=0; i<personVector.size(); i++){
		cout << "Element #" << i << " has value " << personVector[i].getName() << endl;
	}
	
	vector<Person>::iterator personIterator; 
	
	for(personIterator = personVector.begin();
		personIterator !=personVector.end();
		personIterator++)
	{
		cout << personIterator->getName() << endl;
		cout << (*personIterator).getName() << endl;
	}
	personVector.erase(personVector.begin(), personVector.end());
		
	return 0;
}
