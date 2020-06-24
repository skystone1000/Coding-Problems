// Codechef June Long Challange 2020
// Contest Code:JUNE20B - Problem Code:CHFICRM
// 3 - Chef and Icecream

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
        int n;
        cin>>n;
        int c5=0,c10 = 0;
        
        vector<int> customer;
        for(int i=0;i<n;i++){
            int tempIn;
            cin>>tempIn;
            customer.push_back(tempIn);
        }
        
        int flag = 0;
        for(int i=0;i<n;i++){
            if(customer[i] == 5){
                c5++;
            }else if(customer[i] == 10){
                if(c5 > 0){
                    c5--;
                    c10++;
                }else{
                    flag = 1;
                    break;
                }
            }else if(customer[i] == 15){
                if(c10 > 0){
                    c10--;
                }else if(c5 > 1){
                    c5 = c5 -2;
                }else{
                    flag = 1;
                    break;
                }
            }
        } 

        if(flag == 0){
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }


    }
    return 0;
}
