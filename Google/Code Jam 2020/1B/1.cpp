// 
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        /*string str;
        getline(cin, str); 
        
        string a;
        cin>>a;*/

        int X,Y;
        cin>>X>>Y;
        string ans;

        int cors[100000][2];
        string dir[100000];
        cors[0][0] = 0;
        cors[0][1] = 0;

        int end = 0;
        for(int i=0;i<100;i++){
            int x = cors[i][0];
            int y = cors[i][1];
            //N
            end++;
            cors[end][0] = x;
            cors[end][1] = y+1;
            dir[end] = dir[i] + 'N'; 
            //S
            end++;
            cors[end][0] = x;
            cors[end][1] = y-1;
            dir[end] = dir[i] + 'S';
            //E
            end++;
            cors[end][0] = x+1;
            cors[end][1] = y;
            dir[end] = dir[i] + 'E';
            //W
            end++;
            cors[end][0] = x-1;
            cors[end][1] = y;
            dir[end] = dir[i] + 'W';

        }    
        //cout<<"END = "<<end<<endl;
        //cout<<"X    "<<"Y    "<<"Path\n";
        int found = 0;
        cout<<"Case #"<<testCases+1<<": ";
        for(int i=0;i<end;i++){
            if(X == cors[i][0] && Y == cors[i][1]){
                cout<<cors[i][0]<<" "<<cors[i][1]<<" "<<dir[i]<<endl;
                found = 1;
                break;
            }
            //cout<<cors[i][0]<<"    "<<cors[i][1]<<"    "<<dir[i]<<endl;
        }    
        if(found == 0){
            cout<<"IMPOSSIBLE\n";
        }

    }
    return 0;
}