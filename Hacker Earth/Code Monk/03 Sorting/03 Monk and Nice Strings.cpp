// Monk and Nice Strings

#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    string strs[n];
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        strs[i] = temp;

        // Calculating niceness of current string
        int niceness=0;
        for(int j=0;j<i;j++){
            if(strs[j] < strs[i])
                niceness++;
        }
        cout<<niceness<<endl;
    }
    return 0;
}