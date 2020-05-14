// 
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int testCases,i,t;
    cin>>testCases;
    for(t=0;t<testCases;t++){
        long long int n;
        cin>>n;
        vector <int> a;
        for(int i=0;i<n;i++){
            a.push_back(0);
        }

        for(int k=0;k<n;k++){

            int size=0;
            int lptr=0,rptr=0,l=0,r=0;

            for(int i=0;i<n;i++){
                if(a[l]==0){
                    r = l+1;
                    while(a[r] == 0){
                        r++;
                    }
                    if(size < r-l){
                        size =r-l;
                        lptr = l;
                        rptr = r;
                    }
                }else{
                    l++;
                }
            }

            //cout<<"l="<<l<<" r="<<r<<endl;

            if(lptr+rptr % 2 == 0){
                a[(lptr+rptr)/2] = k+1;
            } else if(lptr+rptr % 2 == 1){
                a[(lptr+rptr-1)/2] = k+1;
            }

        }

        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}