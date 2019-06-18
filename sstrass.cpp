//sstrass.cpp
//defining and assigning string objects
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("Man");
	string s2 = "Beast";
	string s3; 
	
	s3 = s1;
	cout << "\ns3 = " << s3 << endl;
	
	s3 = "Neither " + s1 + " nor " + s2; 
	cout << "\ns3 = " << s3 << endl;
	
	s1.swap(s2);
	s3 = "Neither " + s1 + " nor " + s2; 
	cout << "\ns3 = " << s3 << endl;

	return 0; 
}
