#include<iostream>
#include<vector>

using namespace std;

string revFunc() {
    string a;
    cin>>a;
    vector<string> arr;
    string word = "";
    for(int i=0;i<a.size();i++){
        if(a[i] == '.'){
                arr.push_back(word);
                word = "";
        } else {
                word += a[i];
        }

        if(i == a.size()-1){
                arr.push_back(word);
                word = "";
        }
    }
    
    string finalStr;
    for(int i=arr.size()-1;i>=0;i--){
        if(i == 0){
                finalStr += arr[i];
        } else {
                finalStr += arr[i] + ".";
        }
    }
    
    return finalStr;
}


int main(){

    // string a = "i.like.this.program.very.much";
    
    string finalStr = revFunc();
    cout<<finalStr<<endl;

    return 0;
}
