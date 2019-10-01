#include "std_lib_facilities.h"

int main(){

	/*char c;
	int szam, szam2;
	int szamol=0;
	cout<<"Please enter a number: ";
	cin>>szam;
	++szamol;
	
	while (cin.get(c)&&c!='|'){
		if(szamol==1){
		
		cout<<"Please enter an another number: ";
		cin>>szam2;
		++szamol;
		}
		else if(szamol==2){
			cout<<"Please enter a number: ";
			cin>>szam;
			cout<<"Please enter an another number: ";
			cin>>szam2;
		}
		
	}
*/

/*	int szam=0;
	int szam2=0;
	int szamol=0;
	
	cout<<"Please enter a number: ";
	while(cin>>szam){
		cout<<"Please enter an another number: ";
		cin>>szam2;
		
		cout<<szam<<"\n";
		cout<<szam2<<"\n";
		cout<<"\n";
		++szamol;
		if(szam>szam2){
			cout<<"The larger value is: "<<szam<<"\n";
			cout<<"The smaller value is: "<<szam2<<"\n";
			
		}
		else if(szam<szam2){
			cout<<"The larger value is: "<<szam2<<"\n";
			cout<<"The smaller value is: "<<szam<<"\n";
		}
		else if(szam==szam2){
			cout<<"The numbers are equal \n";
		}
		
		if(szamol>0){
			cout<<"Please enter a number: ";
			
		}
		
	}
		*/	
			


	/*double szam=0;
	double szam2=0;
	int szamol=0;
	
	cout<<"Please enter a number: ";
	while(cin>>szam){
		cout<<"Please enter an another number: ";
		cin>>szam2;
		
		cout<<szam<<"\n";
		cout<<szam2<<"\n";
		cout<<"\n";
		++szamol;
		if(szam>szam2){
			cout<<"The larger value is: "<<szam<<"\n";
			cout<<"The smaller value is: "<<szam2<<"\n";
			
		}
		else if(szam<szam2){
			cout<<"The larger value is: "<<szam2<<"\n";
			cout<<"The smaller value is: "<<szam<<"\n";
		}
		else if(szam==szam2){
			cout<<"The numbers are equal \n";
		}
		
		if((szam-szam2)<1.0/100){
			cout<<"The numbers are almost equal \n";
		}
		else if((szam2-szam)<1.0/100){
			cout<<"The numbers are almost equal \n";
		}
		
		if(szamol>0){
			cout<<"Please enter a number: ";
			
		}
		
	}*/
	
	/*double szam;
	double nagy;
	double kicsi;
	bool k=true;;
	
	cout<<"Please enter a number: ";
	while(cin>>szam){
		if(k==true){
			nagy=szam;
			kicsi=szam;
			k=false;
		}
		if(szam<kicsi){
			cout<<"The smallest so far "<<endl;
			kicsi=szam;
		}
		else if(szam>nagy){
			cout<<"The largest so far "<<endl;
			nagy=szam;
		}
		
		cout<<"Please enter an another number: ";
		
		
	}*/
	
	
	/*
	double szam;
	string mertekegyseg;
	cout<<"Please enter the value of the unit that you want to convert to: ";
	while(cin>>szam>>mertekegyseg){
		
	
		
		if(mertekegyseg=="cm"){
			cout<<szam<<mertekegyseg<<" == "<<szam/100<<"m"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam/2.54<<"in"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam/30.48<<"ft"<<endl;
		}
		else if(mertekegyseg=="m"){
			cout<<szam<<mertekegyseg<<" == "<<szam*100<<"cm"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*39.37<<"in"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*3.28<<"ft"<<endl;
		}
		else if(mertekegyseg=="in"){
			cout<<szam<<mertekegyseg<<" == "<<szam*2.54<<"cm"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*0.0254<<"m"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*0.083<<"ft"<<endl;
		}
		else if(mertekegyseg=="ft"){
			cout<<szam<<mertekegyseg<<" == "<<szam*30.48<<"cm"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*12<<"in"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*0.3048<<"m"<<endl;
		}
		else if(mertekegyseg=="y"|| mertekegyseg=="yard" || mertekegyseg=="meter" || mertekegyseg=="km" || mertekegyseg=="gallons"){
			cout<<"This unit is not allowed. Try again"<<endl;
			cout<<"Please enter the value of the unit that you want to convert to: ";
		}
		else{
			cout<<"Try again"<<endl;
			cout<<"Please enter the value of the unit that you want to convert to: ";
		}
		cout<<"\n";

		
	}
		*/
		
		
		
		
	char c;
	double szam;
	string mertekegyseg;
	double kicsi;//meterben
	double nagy;//meterben
	double sum=0.0;//meterben
	bool k=true;
	vector<double> szamok;
	
	cout<<"Please enter the value of the unit that you want to convert to: ";
	while(cin>>szam>>mertekegyseg){
		if(cin.get()=='|'){
			
			break;
		}
		
		
		if(k==true){
			if(mertekegyseg=="m"){
				nagy=szam;
				kicsi=szam;
				k=false;
				
			}
			else if(mertekegyseg=="cm"){
				nagy=szam/100;
				kicsi=szam/100;
				k=false;
			}
			else if(mertekegyseg=="in"){
				nagy=szam*0.0254;
				kicsi=szam*0.0254;
				k=false;
			}
			else if(mertekegyseg=="ft"){
				nagy=szam*0.3048;
				kicsi=szam*0.3048;
				k=false;
			}
		}
		
		
		
		if(mertekegyseg=="m"){
			sum=sum+szam;
		}
		else if(mertekegyseg=="cm"){
				sum=sum+szam/100;
						}
		else if(mertekegyseg=="in"){
				sum=sum+szam*0.0254;
		}
		else if(mertekegyseg=="ft"){
				sum=sum+szam*0.3048;
		}
		
	
		if(szam<kicsi){
			if(mertekegyseg=="m"){
				kicsi=szam;
			}
			else if(mertekegyseg=="cm"){
				kicsi=szam/100;
			}
			else if(mertekegyseg=="in"){
				kicsi=szam*0.0254;
			}
			else if(mertekegyseg=="ft"){
				kicsi=szam*0.3048;
			}
			
		}
		else if(szam>nagy){
			if(mertekegyseg=="m"){
				nagy=szam;
			}
			else if(mertekegyseg=="cm"){
				nagy=szam/100;
			}
			else if(mertekegyseg=="in"){
				nagy=szam*0.0254;
			}
			else if(mertekegyseg=="ft"){
				nagy=szam*0.3048;
			}
		}
		
		if(mertekegyseg=="cm"){
			cout<<szam<<mertekegyseg<<" == "<<szam/100<<"m"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam/2.54<<"in"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam/30.48<<"ft"<<endl;
			szamok.push_back(szam/100);
		}
		else if(mertekegyseg=="m"){
			cout<<szam<<mertekegyseg<<" == "<<szam*100<<"cm"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*39.37<<"in"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*3.28<<"ft"<<endl;
			szamok.push_back(szam);
		}
		else if(mertekegyseg=="in"){
			cout<<szam<<mertekegyseg<<" == "<<szam*2.54<<"cm"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*0.0254<<"m"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*0.083<<"ft"<<endl;
			szamok.push_back(szam*0.0254);
		}
		else if(mertekegyseg=="ft"){
			cout<<szam<<mertekegyseg<<" == "<<szam*30.48<<"cm"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*12<<"in"<<endl;
			cout<<szam<<mertekegyseg<<" == "<<szam*0.3048<<"m"<<endl;
			szamok.push_back(szam*0.3048);
		}
		else if(mertekegyseg=="y"|| mertekegyseg=="yard" || mertekegyseg=="meter" || mertekegyseg=="km" || mertekegyseg=="gallons"){
			cout<<"This unit is not allowed. Try again"<<endl;
			cout<<"Please enter the value of the unit that you want to convert to: ";
		}
		else{
			cout<<"Try again"<<endl;
			cout<<"Please enter the value of the unit that you want to convert to: ";
		}
		cout<<"\n";
		cout<<"Please enter the value of the unit that you want to convert to: ";
		
	}
			cout<<"\n";
			cout<<"The gratest number: "<<nagy<<endl;
			cout<<"The smalest number: "<<kicsi<<endl;                                        |
			cout<<"Sum: "<<sum<<endl;
			cout<<"\n";
			
			sort(szamok);
			
			for(double x:szamok){
				cout<<x<<"  ";
			}
		
		return 0;


	
}