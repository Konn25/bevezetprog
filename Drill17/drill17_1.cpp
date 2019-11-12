#include <iostream>
#include <vector>

using namespace std;


ostream& print_array10(ostream& os, int* a){
    for(int i=0;i<10;++i){
        os<<a[i]<<"\n";
    }
    return os;
}

ostream& print_array(ostream& os, int* a, int n){
    for(int i=0;i<n;i++){
        os<<a[i]<<"\n";
    }
    return os;
}

ostream& print_vector(ostream& os, vector<int>& v){
    for(int i=0;i<v.size();i++){
        os<<v[i]<<"\n";

    }
    return os;
}



int main(){
  /*
    int* szamok= new int[10];
    int x=1;
    for(int i=0;i<10;++i){
        szamok[i]=x;
        ++x;
    }

    for(int i=0;i<10;++i){
        cout<<szamok[i]<<"\n";

    }
    cout<<"\n";
    print_array10(cout, szamok);
    cout<<"\n";
    print_array(cout,v11,20);

    delete[] szamok;
*/

    vector<int> szam (10);
    int y=100;
    for(int i=0;i<szam.size();++i){
        szam[i]=y;
        ++y;
    }

    /*for(int i=0;i<szam.size()-1;++i){
        cout<<szam[i]<<"\n";

    }*/
    print_vector(cout,szam);
    cout<<"\n";

    szam.erase(szam.begin());
    vector<int> v11(11);
    int z=100;
    for(int i=0;i<v11.size();++i){
        v11[i]=z;
        ++z;
    }

  /*  for(int i=0;i<v11.size();++i){
        cout<<v11[i]<<"\n";

    }*/
    print_vector(cout,v11);
    cout<<"\n";
    v11.erase(v11.begin());

    vector<int> v20(20);
    int k=100;
    for(int i=0;i<v20.size();++i){
        v20[i]=k;
        ++k;
    }
    print_vector(cout,v20);
    cout<<"\n";
    v20.erase(v20.begin());

    return 0;
}

