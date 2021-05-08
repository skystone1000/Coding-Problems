// May Challenge 2021 - Day 8 - #0906. Super Palindromes
// #0906. Super Palindromes
// https://leetcode.com/problems/super-palindromes/

class Solution {
public:
    
    bool isPallindrome(string s){
        string rev = s;
        reverse(rev.begin(),rev.end());
        return s == rev;
    }
    
    int superpalindromesInRange(string left, string right){
        long long l = stoll(left);
        long long r = stoll(right);
        vector<long long> store;
        
        for(int i=1;i<10;i++)
            store.push_back(i);
        
        for(int i=1;i<=1e4;i++){
            string s1 = to_string(i);
            string s2 = to_string(i);
            reverse(s2.begin(),s2.end());
            
            // even length palindromes
            store.push_back(stoll(s1+s2));
            // odd length palindromes
            for(int j=0;j<10;j++){
                string temp;
                temp = s1 + to_string(j) + s2;
                store.push_back(stoll(temp));
            }
        }
        
        int ans = 0;
        for(auto it:store){
            if(it>1e9)
                continue;
            long long num = it*it;
            if(num<=r and num>=l and isPallindrome(to_string(num)))
                ans++;
        }
        
        return ans;
    }
};