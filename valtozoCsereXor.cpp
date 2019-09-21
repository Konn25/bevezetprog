#include "std_lib_facilities.h"

int main(){
	
	int a=7;
	int b=5;
	cout<<"Eredeti ertekek \n";
	cout<<"a: "<<a<<" "<<"b: "<<b<<"\n";
	
	a=a^b;
	b=b^a;
	a=a^b;
	
	cout<<"Megcserelt ertekek \n";
	cout<<"a: "<<a<<" "<<"b: "<<b;
	
	return 0;
}