// 04 Chef and Bitwise Product - Problem Code: CHANDF
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long int testCases,i;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        pair<int, int> Positions[n]; 
        for (int i = 0; i < n; i++) { 
            Positions[i].first = arr[i]; 
            Positions[i].second = i; 
        } 
        sort(Positions, Positions + n); 

        vector<bool> visited(n, false); 
        int ans = 0; 
        for (int i = 0; i < n; i++) { 
            if (visited[i] || Positions[i].second == i) {
                continue; 
            }
            int cycle_size = 0; 
            int j = i; 
            while (!visited[j]) { 
                visited[j] = 1; 
                j = Positions[j].second; 
                cycle_size++; 
            } 

            if (cycle_size > 0) { 
                ans += (cycle_size - 1); 
            } 
        } 

        cout<<ans<<endl;
    }
    return 0;
}