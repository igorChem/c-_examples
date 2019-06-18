// smartpointer.cpp
// smart pointer exemple 

#include <iostream>
#include <string> 
using namespace std; 

class RefCount {
	
	private:
		int count;
	public:
		void AddRef()
			{ count++;} 
		int Release()
			{return --count;}
};

template <typename T> class SmartPointer{
	
	private:
		T* pData; // pointer 
		RefCount* reference; // pointer to the RefCount reference 
	public:
		SmartPointer() : pData(0), reference(0) {
			reference = new RefCount(); // crete a new pointer object of class refCount
			reference->AddRef();
		}
		
		SmartPointer(T* pValue) :pData(pValue), reference(0) {
			reference = new RefCount(); 
			reference->AddRef();
		}
		SmartPointer(const SmartPointer<T>& sp) : pData(sp.pData), reference(sp.reference){
			// copy constructor 
			reference->AddRef(); 
		}
		
		~SmartPointer(){
			int refCount = reference->Release(); // decrease the reference counter value and return it to a variable
			cout << "Destructor called.. current reference count =" << refCount << endl;
			if (refCount == 0){
				delete pData;
				delete reference;
				cout << "RefCount 0, delete the underlying data" << endl; 
			}
		}
		
		T& operator* (){
			return *pData; 
		}
		T* operator-> (){
			return pData;
		}
		
		SmartPointer<T>& operator= (const SmartPointer<T>& sp) {
			if (this != &sp){
				if(reference->Release() == 0)
				{
					delete pData; 
					delete reference; 
				}
				pData = sp.pData;
				reference = sp.reference;
				reference->AddRef();
			}
			return *this;
		}
};

int main() {
	
	SmartPointer<string> p(new string("vitthal Srinivasan"));
	
	{
		SmartPointer<string> q = p; 
		cout << *q << endl; 
		
		SmartPointer<string> r;
		r = p;
		cout << *p << endl; 
		
	}
	
	cout << *p << endl;
	
	return 0;
}
