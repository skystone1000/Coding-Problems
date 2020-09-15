#include<iostream>
#include<vector>

using namespace std;

void Func(vector<int> &arr) {
    
    for(auto ele:arr){
        if(ele % 5 == 4){
            cout<<ele<<" ";
        }
    }
}

int main(){
    vector<int> arr = {13,4};
    Func(arr);
    return 0;
}
