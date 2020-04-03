// 08 Factorial!
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int fact=1;
    for(int i=1;i<n+1;i++){
        fact *=i;
    }
    cout<<fact<<endl;
    return 0;
}