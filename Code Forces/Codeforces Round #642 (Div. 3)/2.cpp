// 
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        long long int n,k;
        cin>>n>>k;
        vector<long long int> a,b;
        for(int i=0;i<n;i++){
            long long int inp;
            cin>>inp;
            a.push_back(inp);
        }
        for(int i=0;i<n;i++){
            long long int inp1;
            cin>>inp1;
            b.push_back(inp1);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());

        for(int i=0;i<k;i++){
            if(a[i] < b[i]){
                long long int temp = b[i];
                b[i] = a[i];
                a[i] = temp;
            }else{
                break;
            }
        }

        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum +=a[i];
        }

        cout<<sum<<endl;

    }
    return 0;
}