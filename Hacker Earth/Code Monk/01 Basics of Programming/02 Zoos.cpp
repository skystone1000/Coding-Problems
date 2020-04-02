// 02 Zoos
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str; 
  
    getline(cin, str); 
    int length = str.length();
    int x=0,y=0;

    for(int i=0;i<length;i++){
        char temp = str[i];
        if(temp == 'z' ){
            x++;
        }
        else if(temp == 'o' ){
            y++;
        }
    }
    if(2*x == y){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}