#include<bits/stdc++.h>
using namespace std;

int parent[10000];
int rankArr[10000];

int n=5; // Total Nodes

void makeSet(){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        rankArr[i] = 0;
    }
}

// 7 -> 6 -> 4 -> 3
int findPar(int node){
    if(node ==parent[node])
        return node;
    
    // Brute force
    // return findPar(parent[node]);

    // Path Compression
    return parent[node] = findPar(parent[node]);
}

void unionOperation(int u, int v){
    u = findPar(u);
    v = findPar(v);

    if(rankArr[u] < rankArr[v])
        parent[u] = v;
    else if(rankArr[v] < rankArr[u])
        parent[v] = u;
    else{
        parent[v] = u;
        rankArr[u]++;
    }
}

int main(){
    makeSet();
    int m;
    cin>>m;
    while(m--){
        int u, v;
        unionOperation(u,v);
    }

    // if 2 and 3 belong to the same component or not
    if(findPar(2) != findPar(3))
        cout<< "DIfferent Component";
    else
        cout<< "Same";
}