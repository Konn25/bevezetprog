#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

ostream& print_array(ostream& os, int* a, int n){
    for(int i=0;i<n;i++){
        os<<a[i]<<"\n";
    }
    return os;
}

ostream& print_vector(ostream& os, vector<int>& v){
    for(int i=0;i<v.size();i++){
        os<<v[i]<<"\t";

    }
    return os;
}

int main(){

int k=7;

int* p1 =&k;

cout<<"p1 address and value: "<<p1<<" ------> "<<*p1;

int* p2= new int [7];

int x=1;
for(int i=0;i<7;++i){
    p2[i]=x;
    x *=2;

}
cout<<"\n";
cout<<"\n";

cout<<"p2 address: ----> "<<p2<<"\n";
cout<<"p2 values: ";
for(int i=0;i<7;++i){
    cout<<p2[i]<<"\t";

}
//print_array(cout,p2,7);

cout<<"\n";
cout<<"\n";

int* p3=p2;
p1=p2;
p3=p2;

cout<<"Pointer: "<<p1<<" points to "<<*p1<<"\n";
cout<<"Pointer: "<<p2<<" points to "<<*p2<<"\n";

delete[] p2;

p1=new int[10]{1,2,4,8,16,32,64,128,248,512} ;
p2=new int[10];

for(int i=0;i<10;++i){
    p2[i]=p1[i];
}
cout<<"\n";
cout<<"\n";
cout<<"p2 array: ";
    for(int i=0;i<10;++i){
        cout<<p2[i]<<"\t";
    }

cout<<"\n";
cout<<"\n";

//vector 10-12

vector<int> v1 {1,2,4,8,16,32,64,128,248,512};
vector<int> v2 (10);
v2=v1;
cout<<"v2 values: ";
print_vector(cout,v2);



}
