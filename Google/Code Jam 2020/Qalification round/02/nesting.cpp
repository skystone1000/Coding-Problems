// 02 Nesting Depth
#include<iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        string s;
        string ans;
        cin>>s;
        int len = s.length();
        int open=0;

        cout<<"Case #"<<t+1<<": ";

        // For each digit
        for(int i=0;i<len;i++){
            int temp = s[i];
            int digit;
            if(temp == 48)
                digit = 0;
            else if(temp == 49)
                digit = 1;
            else if(temp == 50)
                digit = 2;
            else if(temp == 51)
                digit = 3;
            else if(temp == 52)
                digit = 4;
            else if(temp == 53)
                digit = 5;
            else if(temp == 54)
                digit = 6;
            else if(temp == 55)
                digit = 7;
            else if(temp == 56)
                digit = 8;
            else if(temp == 57)
                digit = 9;

            /* 
            If open braces are
                equal to digit : do noting
                less than digit : add braces
                greater than digit : sub braces 
            */

            if(open == digit){
                cout<<digit;
                continue;
            }else if(open<digit){
                string add;
                int till = digit -open;
                for(int j=0;j<till;j++){
                    cout<<"(";
                    //add += '(' ;
                    open++;
                } 
                //cout<<add;
                cout<<digit;
                continue;
            }else if(open>digit){
                string sub;
                int till = open-digit;
                for(int j=0;j<till;j++){
                    cout<<")";
                    //sub += ')' ;
                    open--;
                } 
                //cout<<sub;
                cout<<digit;
                continue;
            }
        }


        // Checking at last if all braces are closed
        if(open != 0){
            string add;
            for (int i=0;i<open;i++){
                add+=")";
            }
            cout<<add;
        }
        cout<<endl;



    }
    return 0;
}