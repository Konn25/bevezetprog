#include <iostream>
#include <vector>

using namespace std;

vector<int> gv{1,2,4,8,16,32,64,128,256,512};

void fe(vector<int> vec){

        cout<<"lv vector:";
        cout<<"\n";
        vector<int> lv(vec.size());
        lv=vec;

        for(int i=0;i<lv.size();++i){
            cout<<lv[i]<<"\t";
        }

        cout<<"\n";
        cout<<"\n";

        cout<<"lv2 vector:"<<"\n";
        vector<int> lv2=vec;

        for(int i=0;i<lv.size();++i){
            cout<<lv[i]<<"\t";
        }
}


int main(){

    cout<<"gv vector"<<"\n";
    cout<<"\n";
    fe(gv);
    cout<<"\n";
    cout<<"\n";

    vector<int> vv {1, 2*1 , 3*2*1 , 4*3*2*1 , 5*4*3*2*1 , 6*5*4*3*2*1 , 7*6*5*4*3*2*1 , 8*7*6*5*4*3*2*1
    , 9*8*7*6*5*4*3*2*1 ,10*9*8*7*6*5*4*3*2*1};

    cout<<"vv vector"<<"\n";
    cout<<"\n";
    fe(vv);
    cout<<"\n";

    return 0;
}
