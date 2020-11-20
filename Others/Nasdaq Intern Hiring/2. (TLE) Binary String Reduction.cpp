// NASDAQ Internship Hiring
// 2. Binary String Reduction
// (TLE) 6 test cases passed 4 TLE

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count = 0;
        while(s.size() > 0){
            char prev = ' ';
            string rem="";
            count++;
            // deb2(count,s);
            for(int i=0;i<s.size();i++){
                if(i==0){
                    prev = s[i];
                }else{
                    // deb2(prev,s[i]);
                    if(prev == s[i]){
                        rem += s[i];
                        prev = s[i];
                    }else{
                        prev = s[i];
                        continue;
                    }
                }
            }
            s = rem;
        }
        cout<<count<<endl;
    }
    return 0;
}

/*
Example
1
10
0100100111

Output
3

*/