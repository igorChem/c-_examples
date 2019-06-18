// Book of object oriented programming classes examples
// distance.cpp

#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////

class Distance
{
	private:
		int feet;
		float inches;
	
	public: 
		Distance(): feet(0), inches(0.0) // construtor sem argumento
		{ }
		
		Distance(int ft, float in): feet(ft), inches(in) // contrutor de 2 argumentos
		{ }
		
		void setdist(int ft, float in) //set Distance to args
		{ feet = ft; inches = in; }
		
		void getdist() //get length from user
		{
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
		}
		
		void showdist() // display distance 
		{ cout << feet << "\'-" << inches << '\"'; }
		
		void add_dist( Distance, Distance ); 	
	
	};
	
void Distance::add_dist(Distance d2, Distance d3) 
{
	inches = d2.inches + d3.inches;
	feet = 0;
	if (inches >= 12.0)
		{
			inches -=12.0;
			feet++; 
		}
	feet += d2.feet + d3.feet;
	
	}
	
int main()
{
	Distance dist1, dist3 ;
	Distance dist2(11, 6.25);
	
	
	dist1.getdist();	
	dist3.add_dist(dist1,dist2);
	
	cout << "\ndist1 = ";dist1.showdist();
	cout << "\ndist2 = ";dist2.showdist();
	cout << "\ndist3 = ";dist3.showdist();
	cout << endl;
		
	return 0;
}

	
	
	
	
	
