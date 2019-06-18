// Book of object oriented programming classes examples
// smallobj.cpp

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////

class smallobj {
	
	private:
	
		int somedata;
	
	public:
	
		void setdata(int d)
		{
			somedata=d;
		}
			
		void showdata()
		{
			cout << somedata << endl;			
		}	
	
	};
	
///////////////////////////////////////////////////////////////////////	

int main()
{
	
	smallobj obj1, obj2;
	
	obj1.setdata(2);
	obj2.setdata(32);
	
	obj1.showdata();
	obj2.showdata();
	
	
	
	return 0;	
	
	}

