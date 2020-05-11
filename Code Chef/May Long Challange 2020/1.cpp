// 01 Coronavirus Spread 
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int N;
        cin>>N;
        vector <int> arr;

        int inp;
        for(int i_Input=0;i_Input<N;i_Input++){
            cin>>inp;
            arr.push_back(inp);
        }

        vector <vector<int>> cluster;

        vector <int> temp;
        for(int i_clust=0;i_clust<arr.size();i_clust++){
            if(i_clust == 0){
                temp.push_back(arr[i_clust]);
            }else if(arr[i_clust] - arr[i_clust-1] < 3){
                temp.push_back(arr[i_clust]);
            }else if(arr[i_clust] - arr[i_clust-1] > 2){
                cluster.push_back(temp);
                temp.clear();
                temp.push_back(arr[i_clust]);
            }
        }

        // Last Cluster
        cluster.push_back(temp);
        temp.clear();

        int max=0 ,min=9999999;        
        for(auto clus: cluster){
            if(clus.size() > max){
                max= clus.size();
            }
            if(clus.size() < min){
                min= clus.size();
            }
        }

        cout<<min<<" "<<max<<endl;
    }
    return 0;
}