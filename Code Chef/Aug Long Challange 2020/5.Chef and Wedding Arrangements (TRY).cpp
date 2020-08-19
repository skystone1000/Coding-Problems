// July Long Challange 2020
// 5.Chef and Wedding Arrangements => Problem Code: CHEFWED
// https://www.codechef.com/AUG20B/problems/CHEFWED

// TRY (NOT COMPLETE)

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

    // Save output to a file
    // freopen ("myfile.txt","w",stdout);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n,k;
        cin>>n>>k;
        map<int,int> guest;
        int maxTable = 0;
        for(int i=0;i<n;i++){
            int tempInp;
            cin>>tempInp;
            guest[tempInp]++;
            if(guest[tempInp] > maxTable){
                maxTable = guest[tempInp];
            }
        }

        int repGuest = 0;
        for(auto ele:guest){
            cout<<ele.first<<"  "<<ele.second<<endl;
            if(ele.second > 1){
                repGuest += ele.second;
            }
        }
        deb(maxTable);
        int minCost = k + repGuest;
        int maxCost = k*maxTable;
        deb2(minCost,maxCost);

    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}
