// Codechef June Long Challange 2020
// Contest Code:JUNE20B - Problem Code:EOEO
// 4 - The Tom and Jerry Game!

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
        long long TS;
        cin>>TS;
        long long count = 0;
        if(TS == 1){
            cout<<"0"<<endl;
            continue;
        }

        if(TS % 2 == 1){
            // If TS is odd
            count = (TS-1)/2;
            cout<<count<<endl;
            continue;
        }
        else{
            // If TS is even
            long long pow2 = 0;

            // Count factos of 2
            long long tempTS = TS;
            while(tempTS % 2 == 0){
                pow2++;
                tempTS = tempTS>>1;
            }
            
            // Lower number which has pow2+1 factors of 2
            long long lower;
            lower = 2<<pow2;
            // mltiples of all lower are possible
            count = (TS-lower) / lower;
            // Adding lower
            if (lower < TS )
                count++;
            cout<<count<<endl; 
        }

    }
    return 0;
}
