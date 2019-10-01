#include "std_lib_facilities.h"

int main(){
	try{
		/*
	/*1.*/ cout << "Success!\n";
	/*2.*/ cout << "Success!\n";
	/*3.*/cout << "Success!" << "\n";
	/*4.*/cout << "Success!" << '\n';
	
	/*5.*/
		int res = 7;
		vector<int> v(10);
		v[5] = res;
		cout << "5. Success!\n";
	/*6.*/
		  vector<int> v(10); 
		  v[5] = 7; 
		  if (v[5]==7) 
			 cout << "Success!\n";
	/*7.*/
		bool cond=true;
		if (cond) 
			cout << "Success!\n"; 
		else 
			cout << "Fail!\n";
 
	/*8.*/
		bool c = false; 
		if (!c) 
			cout << "Success!\n"; 
		else
			cout << "Fail!\n";
	 /*9.*/
	 string s = "ape"; 
	 bool c = "fool" > s;
	 if (c) 
		 cout << "Success!\n";
	
	/*10*/
	 string s = "ape"; 
	 if (s!="fool") 
		 cout << "Success!\n";
	 /*11*/
		vector<char> v(5);
		for (int i=0; i<v.size(); ++i)
			cout << "Success!\n";
		
		/*12*/
		string s = "Success!\n";
		for (int i=0; i<s.size(); ++i) 
			cout << s[i];
		
		/*13*/
		if (true) 
			cout << "Success!\n"; 
		else 
			cout << "Fail!\n";
		
		/*14*/
		int x = 2000;
		char c = x; 
		if (c==2000) 
			cout << "Success!\n";
		
		/*15*/
		s = "Success!\n"; 
		for (int i=0; i<s.size(); ++i) 
			cout << s[i];
		
		/*16*/
		vector<int> v(5); 
		for (int i=0; i<=v.size(); ++i)
			cout << "Success!\n";
		
		/*17*/
		int i=0;
		int j = 9;
		while (j<10) 
			++j; 
			if (j>i) 
				cout << "Success!\n";
			
		/*18*/
		int x = 2; 
		double d = 5/(x–1); 
		if (d==2*(x+0.5)) 
			cout << "Success!\n";
		
		/*19*/
		vector<string> s = "Success!\n"; 
		for (int i=0; i<s.size(); ++i) 
			cout << s[i];
		
		/*20*/
		int i=0; 
		int j=11;
		while (i<10)
			++i; 
			if (j>i) 
				cout << "Success!\n";
			
		/*21*/
		int x = 4; 
		double d = 5/(x–2); 
		if (d=2*x+0.5) 
			cout << "Success!\n";
		
		/*22*/
		 cout << "Success!\n";
		 
		 /*23*/
		    string s = "ape";
			if (s != "fool") 
				cout << "Success!\n";
			
		/*24*/
			string s = "ape";
			string check = "nothing";
				if (check != s + "fool") 
				{ cout << "Success!\n"; }
			
		/*25*/
		vector<char> v(5);
		for (int i = 0; i < v.size(); ++i);
			cout << "Success!\n";
		
 

	 keep_window_open();
	}
		catch (exception& e) {
			cerr << "error: " << e.what() << '\n';
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown exception!\n";
			keep_window_open();
			return 2;
		}
	
}