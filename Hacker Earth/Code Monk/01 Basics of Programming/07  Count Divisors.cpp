// 07 COunt divisiors 
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l,r;
    cin>>l>>r;
    int k;
    cin>>k;
    int count;
    for(int i=l;i<=r;i++){
        if(i%k == 0){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}