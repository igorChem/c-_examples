// mapex.cpp
// map stlvector example 

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
	map <string,string> personMap;
	
	personMap.insert(std::pair<string,string>("Igor","Barden")); // frist way of including key-value pair in maps
	personMap["Naruto"] = "Uzumaki"; //  second way of including key-value pair in maps	
	
	if(personMap.find("Sakura") == personMap.end()){
		cout << "Sakura is not in the map" << endl; }
		
	vector<string> personVector;	
	vector<string> lastNameVector;
	
	for (map<string,string>::iterator mapIterator = personMap.begin();
		mapIterator != personMap.end();
		mapIterator++) {
			personVector.push_back(mapIterator->first);
			lastNameVector.push_back(mapIterator->second);}
	
	vector<string>::iterator personIterator;
	for(personIterator = personVector.begin();
		personIterator != personVector.end();
		personIterator++){
			cout << "Printing persons " << *personIterator << endl;}
			
	vector<string>::iterator stringIterator;
	for(stringIterator = lastNameVector.begin();
		stringIterator != lastNameVector.end();
		stringIterator++){
			cout << "Printing last names " << *stringIterator << endl;}
		
		
}
