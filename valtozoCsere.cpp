#include "std_lib_facilities.h"

int main(){
	int a=7;
	int b=9;
	cout<<"Eredeti ertekek: ";
	cout<<"\n";
	cout<<"a: ";
	cout<< a;
	cout<<"\n";
	cout<<"b: ";
	cout<< b;
	cout<<"\n";
	
	a+=b;
	b=a-b;
	a-=b;
	
	cout<<"A megcserelt ertekek";
	cout<<"\n";
	cout<<"a: ";
	cout<< a;
	cout<<"\n";
	cout<<"b: ";
	cout<< b;
	return 0;
	
	
}