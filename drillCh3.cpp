#include "std_lib_facilities.h"

int main(){
	cout<<"Enter the name of the person you want to write to: ";
	string first_name;
	cin>>first_name;
	cout<<"Dear "<<first_name<<",\n";
	cout<<"How are you? I am fine. I miss you. \n";
	cout<<"Enter the name of your friend:";
	string friend_name;
	cin>>friend_name;
	cout<<"Have you seen "<<friend_name<<" lately?\n";
	char friend_sex='0';
	cout<<"Enter the friend sex (f->female, m->male): ";
	cin>>friend_sex;
	if(friend_sex=='m'){
		cout<<"If you see "<<friend_name<<" please ask him to call me.\n";
	}
	else if(friend_sex=='f'){
		cout<<"If you see "<<friend_name<<" please ask her to call me.\n";
	}
	int age;
	cout<<"Enter the age of the person whose you write the letter:  ";
	cin>>age;
	cout<<"I hear you just had a birthday and you are "<<age+1<<" years old.\n";
	age=age+1;
	if(age<=0){
		simple_error("you're kidding!");
	}
	else if(age>=100){
		simple_error("you're kidding!");
	}
	
	if(age<12){
		cout<<"Next year you will be "<<age+1<<" .\n";
	}
	else if(age==17){
		cout<<"Next year you will be able to vote. \n";
	}
	else if(age>70){
		cout<<"I hope you are enjoying retirement.\n";
	}
	
	cout<<"Yours sincerely, \n";
	cout<<"Enter your name: ";
	string your_name;
	cin>>your_name;
	cout<<"\n\n";
	cout<<your_name;
	
	return 0;
}
