// 10 Roy and Profile Picture
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l,n;
    cin>>l>>n;
    for(int i=0;i<n;i++){
        int wid,ht;
        cin>>wid>>ht;
        if(wid<l || ht<l){
            cout<<"UPLOAD ANOTHER"<<endl;
        }else if(wid == ht){
            cout<<"ACCEPTED"<<endl;
        }else{
            cout<<"CROP IT"<<endl;
        }
    }

    return 0;
}