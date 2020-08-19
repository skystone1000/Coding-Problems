// July Long Challange 2020
// 4.Smallest KMP => Problem Code: SKMP
// https://www.codechef.com/AUG20B/problems/SKMP

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

        string s,p;
        cin>>s>>p;
        int n = s.size();
        vector<char> word(n);
        map<char,int> wordMap;
        for(int i=0;i<n;i++){
            // word[i] = s[i];
            wordMap[s[i]]++;
        }

        // sort(all(word));
        /*
        for(auto x:wordMap){
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<"-----------"<<endl;
        */

        for(int i=0;i<p.size();i++){
            wordMap[p[i]]--;
        }

        /*
        for(auto x:wordMap){
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<"-----------"<<endl;
        */
        
        string checkStr;
        for(auto &x:wordMap){
            for(int i=0;i<x.second;i++){
                checkStr += x.first;
            }
        }

        // cout<<checkStr<<endl;
        
        vector<string> possible;
        for(int i=0;i<n-p.size()+1;i++){
            string temp = checkStr;
            if(i != 0 && checkStr[i-1] == checkStr[i]){
                continue;
            }
            temp.insert(i,p);
            // cout<<i<<" "<<temp<<endl;
            possible.push_back(temp);
        }
        
        string finalAns = possible[0];

        for(int i=0;i<possible.size();i++){
            if(possible[i] < finalAns){
                finalAns = possible[i];
            }
        }
        cout<<finalAns<<endl;
        

    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}
