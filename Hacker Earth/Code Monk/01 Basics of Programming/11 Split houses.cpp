// 11 Split houses
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    char grid[n];
    char prev;
    for(int i=0;i<n;i++){
        cin>>grid[i];
        if(prev == 'H' && grid[i]== 'H' && i!=0){
            cout<<"NO";
            return 0;
        }else if(grid[i] == '.'){
            grid[i] = 'B';
        }
        prev = grid[i];

    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<grid[i];
    }


    return 0;
}