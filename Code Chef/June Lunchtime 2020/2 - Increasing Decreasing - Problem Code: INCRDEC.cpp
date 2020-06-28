// June Lunchtime 2020
// 2 - Increasing Decreasing - Problem Code: INCRDEC

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>

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
        /*
        // Unique
        vector<int>::iterator ip;
        ip = std::unique(v.begin(), v.begin() + 12); 
        v.resize(std::distance(v.begin(), ip)); 
        */
        ll n;
        cin>>n;
        map< int,int > arr;
        for(int i=0;i<n;i++){
            ll temp;
            cin>>temp;
            auto it = arr.find(temp);
            if (it != arr.end()){
                int count = it->second;
                it->second = count + 1;
            }
            else{
                arr.insert({temp,1});
            }
        }
        /*
        cout<<"\n===============\n";
        for (auto itr = arr.begin(); itr != arr.end(); ++itr)
            cout << '\t' << itr->first << '\t' << itr->second << '\n'; 
        */
        int flag = 0;
        
        for (auto itr = arr.begin(); itr != arr.end(); ++itr){
            if(itr->second > 2){
                cout<<"NO"<<endl;
                flag = 1;
                break;
            }

            if(itr == prev(arr.end())){
                if(itr->second > 1){
                    cout<<"NO"<<endl;
                    flag = 1;
                    //cout << '\t' << itr->first << '\t' << itr->second << '\n'; 
                    break;
                }
            }
        }

        if(flag == 1){
            continue;
        }else{
            cout<<"YES"<<endl;
            for (auto itr = arr.begin(); itr != arr.end(); ++itr){
                cout<< itr->first <<" ";
                itr->second = itr->second - 1;
            }
            

            for (auto itr = arr.rbegin(); itr != arr.rend(); ++itr){
                if(itr->second > 0){
                    cout<< itr->first <<" ";
                }
                // itr->second = itr->second - 1;
            }
            cout<<endl;
        }

    }
    return 0;
}
