// seekg.cpp
// seeks particular person in file
#include <fstream>
//for file streams
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class person{ 

	protected:
		char name[80];
		//person’s name
		short age;
		//person’s age
	public:
		void get_data(){
		cout << "\n	Enter name: "; cin >> name;
		cout << "Enter age: "; cin >> age;
		}
		void showData(){
			cout << "\n Name: " << name;
			cout << "\n Age: " << age;				
		}
		
};
//////////////////////////////////////////////////

int main(){
	
	person pers;
	ifstream infile;  // input object 
	infile.open("GROUP.DAT",ios::in | ios::binary); 
	
	infile.seekg(0,ios::end); // go to 0 bytes from end
	int endposition = infile.tellg(); //find the current position
	int n = endposition/ sizeof(person); // number of persons objects in the file
	cout << "\nthere are " << n << " persond in file"; 
	
	cout << "\nEnter person number: "; 
	cin >> n; 
	int position = (n-1)*sizeof(person); // position of person n in the file
	infile.seekg(position); // set the file to read n person
	
	infile.read( reinterpret_cast<char*>(&pers),sizeof(pers) ) ;
	pers.showData();
	cout << endl; 
	
	return 0;
}
