// Kick Start 2020 Round G
// 

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        string s;
        cin>>s;

        if(s.size() < 9){
            cout<<"Case #"<<t+1<<": "<<0<<endl;
            continue;
        }

        vector<int> kick;
        vector<int> start;
        for(int i=0;i<s.size()-3;i++){
            string w1 = s.substr(i,4);
            string w2 = s.substr(i,5);
            if(w1 == "KICK"){
                kick.push_back(i);
                //i = i+3;
                //continue;
            }
            if(w2 == "START"){
                start.push_back(i);
                //i = i+4;
                
            }
        }

        /*
        for( int ele:kick){
            cout<<ele<<" ";
        }
        cout<<endl;
        for(int ele:start){
            cout<<ele<<" ";
        }*/

        int count = 0;
        for(int i=0;i<kick.size();i++){
            for(int j=0;j<start.size();j++){
                if(kick[i] < start[j]){
                    count += start.size() - j;
                    break;
                }
            }
        }
        cout<<"Case #"<<t+1<<": "<<count<<endl;

    }
    return 0;
}
