// Pepcoding - Inverse Of A Number
// Ques - https://www.pepcoding.com/resources/online-java-foundation/getting-started/inverse-of-a-number-official/ojquestion
// Soln - https://www.pepcoding.com/resources/online-java-foundation/getting-started/inverse_of_number/topic

// Method 1 - Extra space
#include <iostream>
#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    vector<pair<int , int>> arr;
    int i=1;
    while(n > 0){
        int digit = n % 10;
        arr.push_back({digit, i});
        i++;
        n = n / 10;
    }
    
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans += arr[i].second * pow(10, arr[i].first-1);
    }
    cout<<ans;
}

// Method 2 - No extra space
#include <iostream>
#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    int i=1;
    int ans=0;
    while(n > 0){
        int digit = n % 10;
        i++;
        n = n / 10;
        
        ans += (i-1) * pow(10, digit-1);
    }
    cout<<ans;
}