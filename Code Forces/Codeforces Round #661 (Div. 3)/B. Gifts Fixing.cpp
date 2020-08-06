// Codeforces Round #661 (Div. 3) Editorial
// B. Gifts Fixing
// https://codeforces.com/contest/1399/problem/B

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){

        // Save output to a file
        // freopen ("myfile.txt","w",stdout);

        /*string str;
        getline(cin, str); 
        
        string a;
        cin>>a;
        
        // int to string
        string tempSumStr = to_string(73846)

        // String to int
        string str1 = "31337 sdkh"; 
        int myint1 = stoi(str1);  // output => 31337

        const char *str1 = "31337 sdkj"; 
        int num1 = atoi(str1); 
        
        // To Lower case
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // Unique
        vector<int>::iterator ip;
        ip = std::unique(v.begin(), v.begin() + 12); 
        v.resize(std::distance(v.begin(), ip)); 

        // Find 
        std::vector<int>::iterator it; 
        it = std::find (vec.begin(), vec.end(), required); 
        if (it != vec.end()) 
            std::cout << "Element " << required <<" found at : "<< it - vec.begin(); 
        else
            std::cout << "Element not found"; 
        */
        int n;
        cin>>n;
        vector<ll> a(n);
        vector<ll> b(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        ll minA = a[0],minB = b[0];
        for(int i=0;i<n;i++){
            if(minA > a[i])
                minA = a[i];
            if(minB > b[i])
                minB = b[i];
        }
        // cout<<minA<<" "<<minB;
        
        ll steps = 0;
        for(int i=0;i<n;i++){
            ll temp1 = a[i] - minA;
            ll temp2 = b[i] - minB;
            if(temp1 > temp2){
                steps += temp1;
            } else {
                steps += temp2;
            }
        }

        cout<<steps<<endl;
        
    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}
