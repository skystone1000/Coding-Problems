/* Print

   *
  *** 
 ***** 
*******
 ***** 
  *** 
   *

*/

#include<iostream>

using namespace std;

int main(){
    // Max stars in a line
    int n = 7;
    int space = n - 1;  
  
    // run loop (parent loop)  
    // till number of rows  
    for (int i = 0; i < n; i++)  
    {  
        // Remove even numberd lines
        if(i%2 == 1){
            space--;  
            continue;
        }

        // loop for initially space,  
        // before star printing  
        for (int j = 0;j < space; j++)  
            cout << " ";  
  
        // Print i+1 stars  
        for (int j = 0; j <= i; j++)  
            cout << "* ";  
  
        cout << endl;  
        space--;  
    }  
  
    // Repeat again in reverse order  
    space = 1;  
  
    // run loop (parent loop)  
    // till number of rows  
    for (int i = n-1; i > 0; i--)  
    {   
        // Remove even numberd lines
        if(i%2 == 0){
            space++; 
            continue;
        }

        // loop for initially space,  
        // before star printing  
        for (int j = 0; j < space; j++)  
            cout << " ";  
  
        // Print i stars  
        for (int j = 0;j < i;j++)  
            cout << "* "; 
  
        cout << endl; 
        space++;  
    }
    return 0;
}

/*
    OUTPUT:

skystone@skystone-HP-Notebook:/opt/lampp/htdocs/github/Coding-Problems/Others/Temp$ g++ 1.cpp
skystone@skystone-HP-Notebook:/opt/lampp/htdocs/github/Coding-Problems/Others/Temp$ ./a.out

      * 
    * * * 
  * * * * * 
* * * * * * * 
  * * * * * 
    * * * 
      * 

*/