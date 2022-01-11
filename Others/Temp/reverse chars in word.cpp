#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    string str = "hello world";

    vector<string> all;
    string temp;
    for(int i=0;i<str.size();i++){
        if(str[i] == ' '){
            all.push_back(temp);
            temp = "";
        }else{
            temp += str[i];
        }
    }
    all.push_back(temp);

    string ans;
    for(int i=0;i<all.size();i++){
        reverse(all[i].begin(), all[i].end());
        all[i][0] = toupper(all[i][0]);
        ans += all[i] + ' ';
        
    }

    cout<<ans;

    return 0;
}
