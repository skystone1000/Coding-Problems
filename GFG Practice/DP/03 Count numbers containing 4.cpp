// GFG Practice
// 03 DP
// Count numbers containing 4
// https://practice.geeksforgeeks.org/problems/count-numbers-containing-4/0

#include <iostream>
using namespace std;

int main() {
    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n;
        int count=0;
        cin>>n;
        for(int i=0;i<=n;i++){
            int check = i;
            while(check != 0){
                if(check % 10 == 4){
                    // cout<<check<<endl;
                    count++;
                    break;
                }
                check = check/10;
            }
        }
        cout<<count<<endl;
    }
	//code
	return 0;
}