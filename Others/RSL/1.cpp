#include<iostream>
#include<vector>

using namespace std;

string repFunc() {
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
    for(int i=0;i<arr.size();i++){
        if(i % 2 == 1){
                finalStr += "abc";
        } else {
                finalStr += arr[i];
        }

        if(i != arr.size()){
                finalStr += finalStr + '.';
        }
    }
    
    return finalStr;
}


int main(){

    // string a = "i.like.this.program.very.much";
    
    string finalStr = repFunc();
    cout<<finalStr<<endl;

    return 0;
}
