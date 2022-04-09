//
// 

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<stack>
#define modulo 1000000007

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

using namespace std;

void populate(int curr, string s, set<string> &possible){
    if(curr>s.size()-1)
        return;
    
    possible.insert(s);

    string newS = "";
    for(int i=0;i<s.size();i++){
        if(i==curr){
            newS = newS + s[i] + s[i];
        }else{
            newS = newS + s[i];
        }
    }
    possible.insert(newS);

    populate(curr+2, newS, possible);
    populate(curr+1, s, possible);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        string s;
        cin>>s;
        cout<<"Case #"<<t+1<<": ";
        set<string> possible;
        populate(0, s, possible);

        for(auto ele:possible){
            cout<<ele<<endl;
            break;
        }
    }
    return 0;
}
