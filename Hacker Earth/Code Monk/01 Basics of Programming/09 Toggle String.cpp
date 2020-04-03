// 09 Toggle String
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    getline(cin, str); 
    
    int len= str.length();
    
    for(int i=0;i<len;i++){
        int a;
        if(str[i] < 92){
            a= int(str[i])+32;
            cout<<char(a);
        } else{
            a= int(str[i])-32;
            cout<<char(a);
        }
    }

    return 0;
}