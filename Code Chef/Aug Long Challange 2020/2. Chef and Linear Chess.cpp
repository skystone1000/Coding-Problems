// July Long Challange 2020
// 2. Chef and Linear Chess => Problem Code: LINCHESS
// https://www.codechef.com/AUG20B/problems/LINCHESS


Chef and Linear Chess Problem Code: LINCHESS
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>

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
        ll h,p;
        cin>>h>>p;
        // if(h>= 2*p){
        //     cout<<"0"<<endl;
        //     continue;
        // }
        while(p>0 && h > 0){
            h = h-p;
            p = p/2;
        }

        if(h <= 0){
            cout<<"1"<<endl;
        }else if(p<=0){
            cout<<"0"<<endl;
        }


    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}
