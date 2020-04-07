// 04 Little monk and good string
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    cin>>a;
    int lenS = a.length();

    int max=0;
    for(int i=0;i<a.length();i++){
        int count=0;
        for(int j=i;j<a.length();j++){
            if(a[j] == 'a' || a[j] == 'e' || a[j] == 'i' ||
                a[j] == 'o' || a[j] == 'u' ){
                    count++;
            } else {
                break;
            }
        }

        if (count>max){
            max = count;
        }

        // Some Large test cases had all vowels but very large 
        // Other wise there was TLE
        if(max == lenS){
            break;
        }
    }

    cout<<max<<endl;

    return 0;
}