// 
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

char check(int i,int j,int stackCount);
int n;
vector<char> ins;
vector<char> out;

int main(){

    freopen ("Finalfile.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        /*
        string str;
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
        cout<<"Case #"<<t+1<<":"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            char tempChar;
            cin>>tempChar;
            ins.pb(tempChar);
        }
        for(int i=0;i<n;i++){
            char tempChar;
            cin>>tempChar;
            out.pb(tempChar);  
        } 

        vector<vector<char>> ans;
        for(int i=0;i<n;i++){
            vector<char> tempCal;
            for(int j=0;j<n;j++){
                int stackCount = 0;
                char outChar = check(i,j,stackCount);
                tempCal.pb(outChar);
            }
            ans.pb(tempCal);
        }

        for(auto &x:ans){
            for(auto &y:x){
                cout<<y;
            }
            cout<<endl;
        }

        ins.clear();
        out.clear();
    }
    
    
    fclose (stdout);
    return 0;

}

char check(int i,int j,int stackCount){
    if(stackCount != 0){
        if(out[j] == 'N'){
            return 'N';
        }
    }

    if(i==j){
        return 'Y';
    }else if(out[i] == 'N'){
        return 'N';
    }else if(ins[j] == 'N'){
        return 'N';
    }else{
        if(j>i){
            if(check(i,j-1,stackCount+1) == 'Y'){
                return 'Y';
            }else{
                return 'N';
            }
        }else{
            if(check(i,j+1,stackCount+1) == 'Y'){
                return 'Y';
            }else{
                return 'N';
            }
        }
    }
    
}