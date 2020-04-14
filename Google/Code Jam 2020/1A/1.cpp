// 
#include<iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>

using namespace std;

bool strmatch(char str[], char pattern[], 
            int n, int m) 
{ 
    if (m == 0) 
        return (n == 0); 

    bool lookup[n + 1][m + 1]; 

    memset(lookup, false, sizeof(lookup)); 

    lookup[0][0] = true; 

    for (int j = 1; j <= m; j++) 
        if (pattern[j - 1] == '*') 
            lookup[0][j] = lookup[0][j - 1]; 

    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= m; j++) 
        { 
            if (pattern[j - 1] == '*') 
                lookup[i][j] = lookup[i][j - 1] || 
                            lookup[i - 1][j]; 

            else if (pattern[j - 1] == '?' || 
                    str[i - 1] == pattern[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1]; 

            else lookup[i][j] = false; 
        } 
    } 

    return lookup[n][m]; 
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n;
        cin>>n;
        string patt[n];
        int maxlength = 0;
        string maxStr;

        for(int i=0;i<n;i++){
            cin>>patt[i];
            if(patt[i].length() > maxlength){
                maxlength = patt[i].length();
                maxStr = patt[i];
            }
        }

        //char *str = new char[maxStr.length() + 1];
        //strcpy(str, maxStr.c_str());

        // char* str = const_cast<char*>(maxStr.c_str());
        char* str = strcpy(new char[maxStr.length() + 1], maxStr.c_str());
        char * pch;
        pch = strtok(str,"*");
        while (pch != NULL)
        {
                printf ("%s\n",pch);
            //cout<<pch;
            pch = strtok (NULL, "*");
        }


        int wrong = 0;
        for(int i=0;i<n;i++){
            char *tut = new char[patt[i].length() + 1];
            strcpy(tut, patt[i].c_str());

            if (strmatch(pch, tut, strlen(pch), strlen(tut))) {
                //cout << "Yes" << endl; 
            }
            else{
                //cout << "No" << endl; 
                wrong = 1;
                break;
            }
        }

        cout<<"Case #"<<t+1<<": ";
        if(wrong == 0){
            cout<<pch<<endl;
        }else{
            cout<<"*"<<endl;
        }
        
        /*
        for(int i=0;i<n;i++){
            cout<<patt[i]<<"\n";
        }
        */


    }
    return 0;
}