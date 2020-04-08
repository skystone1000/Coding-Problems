// Monk and Suffix Sort

#include<iostream>

using namespace std;

int main(){
    string str;
    int k;
    cin>>str>>k;
    int length = str.length();
    string suff[length];

    // Generating suffices (string ending with this)
    for(int i=0;i<length;i++){
        string temp;
        for(int j=i;j<length;j++){
            temp += str[j];
        }
        suff[i] = temp;
    }

    for(int i=0;i<length;i++){
        for(int j=0;j<length-i-1;j++){
            if(suff[j] > suff[j+1]){
                string swap = suff[j];
                suff[j] = suff[j+1];
                suff[j+1] = swap;
            }
        }
    }

    // for(int i=0;i<length;i++){
    //     cout<<suff[i]<<endl;
    // }

   cout<<suff[k-1]<<endl;

    return 0;
}

