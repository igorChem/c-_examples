// strobj.cpp
// a string as a class
#include <iostream>
#include <cstring>

using namespace std;

class String 
{
	private:
		enum {SZ =80};
		char str[SZ];
	public: 
			String()
				{str[0]='\0';}
			String(char s[])
				{strcpy(str,s);}
			void display()
				{cout << str << endl;}
			void concat(String s2)
			{
				if (strlen(str) + strlen(s2.str) < SZ)
				{
					strcat(str,s2.str);
				}
				else
				{
					cout << "\nString too long" << endl;
				}
				
			}			
	
	};
	
int main()
{
	String s1("Merry Christmass! ");
	String s2 = "Season's Greetings!";
	String s3;
	
	cout << "\ns1=" << s1.display() << endl;
	cout << "\ns2=" << s2.display() << endl;
	cout << "\ns3=" << s3.display() << endl;
	
	s3 = s1;
	cout << "\ns3=" << s3.display() << endl;

	s3.concat(s2);
	cout << "\ns3=" << s3.display() << endl;
	return 0;
		
	}
