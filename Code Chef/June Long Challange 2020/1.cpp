// Codechef June Long Challange 2020
// Contest Code:JUNE20B - Problem Code:PRICECON
// 1 - Chef and Price Control 

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        long long n,k;
        cin>>n>>k;
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long temp;
            cin>>temp;
            if(temp > k)
                sum = sum + (temp - k);
        }
        cout<<sum<<endl;

    }
    return 0;
}
