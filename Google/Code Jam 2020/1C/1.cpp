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
        string m;
        cin>>X>>Y;
        cin>>m;
        int time = 0;
        int lenA = m.size();
        int xc[lenA],yc[lenA];
        for(int i=0;i<m.size();i++){
            switch(m[i]){
                case 'N':
                    yc[i] = Y + 1;
                    xc[i] = X;
                    Y++;
                    time++;
                    break;
                case 'S':
                    yc[i] = Y - 1;
                    xc[i] = X;
                    Y--;
                    time++;
                    break;
                case 'E':
                    xc[i] = X + 1;
                    yc[i] = Y;
                    X++;
                    time++;
                    break;
                case 'W':
                    xc[i] = X - 1;
                    yc[i] = Y;
                    X--;
                    time++;
                    break;
            }
        }

        //All iNtermediate positions
        /*
        for(int k=0;k<lenA;k++){
            cout<<"Time "<<k+1<<" : "<<xc[k]<<" "<<yc[k]<<endl;
        }
        */

        
        //cout<<"X = "<<X<<" Y = "<<Y<<" Time = "<<time<<endl;
        if(abs(X)+abs(Y) > time){
            cout<<"Case #"<<t+1<<":"<<"IMPOSSIBLE"<<endl;
        }
        else{
            for(int k=0;k<lenA;k++){
                if(abs(xc[k])+abs(yc[k]) <= k+1){
                    
                    if(abs(xc[k])+abs(yc[k]) == 0){
                        cout<<"Case #"<<t+1<<":"<<k+1<<endl;
                    }else{
                        cout<<"Case #"<<t+1<<":"<< abs(xc[k])+abs(yc[k]) <<endl;
                    }
                    
                    cout<<"X = "<<xc[k]<<" Y = "<<yc[k]<<" Time = "<<k+1<<endl;
                    
                    for(int ka=0;ka<lenA;ka++){
                        cout<<"Time "<<ka+1<<" : "<<xc[ka]<<" "<<yc[ka]<<endl;
                    }
                    cout<<"=========="<<endl;
                    
                    break;
                }
            }
        }

        

    }
    return 0;
}