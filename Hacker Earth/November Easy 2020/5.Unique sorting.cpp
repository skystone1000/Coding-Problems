// November Easy '20
// 5.Unique sorting
// https://www.hackerearth.com/challenges/competitive/november-easy-20/algorithm/unique-sorting-17d60d9f/

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
        string even="";
        string odd="";
        string digE="";
        string digO="";
        sort(s.begin(),s.end());
        for(char ele:s){
            int dig = ele - '0';
            int ch = ele - 'a';
            if(dig <= 9){
                if(dig % 2 == 0){
                    digE += ele;
                }else{
                    digO += ele;
                }
            }else{
                if(ch % 2 == 0){
                    even += ele;
                }else{
                    odd += ele;
                }
            }
        }

        string ans = odd + even + digO + digE;
        cout<<ans<<endl;

    }
    return 0;
}
