// Educational Codeforces Round 98 (Rated for Div. 2) 
//
// 

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stack>
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
        stack<char> sq;
        stack<char> ru;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '['){
                sq.push('[');
            }else if(s[i] == '('){
                ru.push('(');
            }else if(s[i] == ']'){
                if(sq.empty() != true){
                    sq.pop();
                    count++;
                }
            }else if(s[i] == ')'){
                if(ru.empty() != true){
                    ru.pop();
                    count++;
                }
            }
        }
        cout<<count<<endl;

    }
    return 0;
}
