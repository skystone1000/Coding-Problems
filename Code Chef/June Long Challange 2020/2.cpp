// Codechef June Long Challange 2020
// Contest Code:JUNE20B - Problem Code:XYSTR
// 2 - Chef and String

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        string s;
        cin>>s;
        
        long long count = 0;
        long long i = 0;
        while(i<s.size()){
            if(s[i] == 'x'){
                if(s[i+1] == 'y'){
                    i++;
                    count++;
                }
            } else {
                if(s[i+1] == 'x'){
                    i++;
                    count++;
                }
            }
            i++;
            if(i >= s.size()){
                break;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
