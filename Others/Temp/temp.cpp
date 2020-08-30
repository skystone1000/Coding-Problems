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

    int number = 2235;

    int res1 = number & 1;
    cout<<res1 <<endl;

    //            outputs 0/1 => 1 : 0
    //         (condition) if true : false
    string res = number & 1 ? "odd":"even" ;
    cout<<res;

   
    return 0;
}
