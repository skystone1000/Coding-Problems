// Codeforces Round #661 (Div. 3) Editorial
// C. Boats Competition
// https://codeforces.com/contest/1399/problem/C

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

int maxCountSameSUM(vector <int> arr, int n);

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
        vector<int> w(n);
        int maxW,minW;
        for(int i=0;i<n;i++){
            cin>>w[i];
            if(i==0){
                maxW = w[i];
                minW = w[i];
            }
            if(maxW < w[i]){
                maxW = w[i];
            }
            if(minW > w[i]){
                minW = w[i];
            }
        }

        int maxAns = 0;
        for(int i=2*minW;i<2*maxW;i++){
            int tempSum = maxCountSameSUM(w, i);
            if(maxAns < tempSum){
                maxAns = tempSum;
            }
        }
        cout<<maxAns<<endl;
    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}

/*
int maxCountSameSUM(vector <int> arr, int n) 
{ 
    // Create a map to store frequency 
    unordered_map<int, int> M; 
  
    // Store counts of sum of all pairs 
    // in the map 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            M[(arr[i] + arr[j])]++; 
  
    int max_count = 0; 
  
    // Find maximum count 
    for (auto ele : M) 
        if (max_count < ele.second) 
            max_count = ele.second; 
  
    return max_count; 
} 
*/

int maxCountSameSUM(vector<int> v, int t)
{
    unordered_map<int, int> um; 
    int total_pairs = 0;


    for (int i : v)
    {   
        um[i]++;
        if (um.find(t - i) != um.end())
            total_pairs++;
    }   
    return total_pairs;
}