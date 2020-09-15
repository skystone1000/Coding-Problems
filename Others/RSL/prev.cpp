/*
B-2: Given a String of length N reverse the whole string without reversing the individual words in it.
Words are separated by dots. (Avoid using inbuilt functions)
If input is “i.like.this.program.very.much”
Output will be “much.very.program.this.like.i”
*/

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // string a = "i.like.this.program.very.much";
    
    string finalStr = revFunc();
    cout<<finalStr<<endl;

    return 0;
}
