#include <iostream>

int ga[10]{1,2,4,8,16,32,64,128,256,512};

void f(int arr[], int n){
    int la[10]={};

    for(int i=0;i<n;++i){
        la[i]=arr[i];
    }

    std::cout<<"Local copy"<<"\n";
    for(int i=0;i<10;++i){
       std::cout<<la[i]<<"\t";
    }

    int* p=new int[n];

    for(int i=0;i<n;++i){
        p[i]=arr[i];
    }
    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"Pointer"<<"\n";

    for(int i=0;i<n;++i){
        std::cout<<p[i]<<"\t";
    }

    std::cout<<"\n";
    std::cout<<"\n";

    delete[] p;
}


int main(){

    std::cout<<"ga array:"<<"\n";


    f(ga,6);

    int aa[10]={1, 2*1 , 3*2*1 , 4*3*2*1 , 5*4*3*2*1 , 6*5*4*3*2*1 , 7*6*5*4*3*2*1 , 8*7*6*5*4*3*2*1
    , 9*8*7*6*5*4*3*2*1 ,10*9*8*7*6*5*4*3*2*1};

    std::cout<<"\n";
    std::cout<<"\n";
    std::cout<<"aa array:"<<"\n";
    f(aa,8);

    return 0;
}

