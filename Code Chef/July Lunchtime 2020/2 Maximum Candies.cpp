// July Lunchtime 2020
// 2 Maximum Candies - Problem Code: CHECHOC
// https://www.codechef.com/LTIME86B/problems/CHECHOC

// Not Correct corner cases causing problem
	
CHECHOC
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
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        ll ans;
        if(n==1 & m==1){
            if(y>2*x){
                cout<<x<<endl;
            }else{
                cout<<y<<endl;
            }
            continue;
        }
        if(y>=2*x){
            ans = n*m*x;
        }else if(y%2==0){ 
            ans = n*m*y/2;
        }else{
            if(n*m %2 == 0){
                ans = ((n*m)*(y/2)) + ((n*m)/2);
            }else{
                ans = ((n*m)*(y/2)) + ((m*n)+1)/2;
            }
            
        }
        cout<<ans<<endl;
    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}
