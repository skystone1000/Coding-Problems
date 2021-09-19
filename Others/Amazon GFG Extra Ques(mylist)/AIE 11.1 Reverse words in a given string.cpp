// Company Amazon
// AIE 11.1 Reverse words in a given string
// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s);
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        cout<<reverseWords(s)<<endl;
    }
}// } Driver Code Ends


string reverseWords(string S) { 
    string curr="";
    reverse(S.begin(), S.end());
    
    string ans = "";
    for(int i=0;i<S.size();i++){
        if(S[i] != '.'){
            curr += S[i];
        }else{
            reverse(curr.begin(), curr.end());
            ans += curr + ".";
            curr = "";
        }
        
        if(i == S.size()-1){
            reverse(curr.begin(), curr.end());
            ans += curr;
        }
    }
    
    return ans;
} 