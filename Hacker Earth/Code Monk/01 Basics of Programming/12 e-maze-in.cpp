// 12 e-maze-in
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    cin>>a;
    int x=0,y=0;
    for(int i=0;i<a.length();i++){
        char action = a[i];
        switch(action){
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            default:
                break;

        }    
    }
    cout<<x<<" "<<y<<endl;

    return 0;
}