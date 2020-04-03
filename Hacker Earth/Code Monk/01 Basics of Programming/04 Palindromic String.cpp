// 04 Palindromic String
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*string str;
    getline(cin, str); */
    
    string a;
    cin>>a;
    string temp;
    for(int i=a.length()-1;i>=0;i--){
        temp += a[i];
    }
    if(temp == a){
        cout<<"YES";
    }else{
        cout<<"NO";
    }


    return 0;
}