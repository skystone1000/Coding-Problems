// 02 Isolation Centers - Problem Code: CORUS
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        unsigned long long int N,Q,i;
        cin>>N>>Q;
        string s;
        cin>>s;
        
        map<char,int> cen;
		map<char,int>:: iterator itr;
		
		for(i=0;i<s.size();i++){
			if( cen.find(s[i]) == cen.end()){
			    cen[s[i]]=1;
            }else{
			    cen[s[i]]++;
            }
		}

		long long int si,sum=0;
		for(i=0;i<Q;i++){
			sum=0;
			cin>>si;
			for(itr=cen.begin();itr!=cen.end();itr++){
                long long int p=itr->second;
                if(p>si)
                sum+=(p-si);
            }		
			cout<<sum<<endl;
		}
    }
    return 0;
}