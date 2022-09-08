/*
A-2​: ​Variation of Fibonacci
The Fibonacci sequence is constructed by adding the last two numbers of the sequence so far to get the
next number in the sequence. The first and the second numbers of the sequence are defined as 0 and 1.
We get:
0, 1, 1, 2, 3, 5, 8, 13, 21...
Write a function which takes input as a number:
●If the given number is a Fibonacci number, print the number
●If the given number is NOT Fibonacci number, print the sum of all even Fibonacci numbers less than the given number.

int getFibOutput(int input) {
      // TODO:
}

Example(21 is a Fibonacci number)Input: 21 Output: 21(20 is NOT a Fibonacci number so, output is 10 (2+8))Input: 20 Output: 10 
=======================================
*/

#include<iostream>
#include<vector>
#include<map>
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl

using namespace std;

int getFibOutput(int input) {
    int a=0,b=1;
    int sum = 0;
    while(b<input){
        // deb2(a,b);
        int c = a+b;
        if(c == input){
            return c;
        }
        if(c % 2 == 0){
            sum += c;
        }
        a = b;
        b = c; 
    }
    
    return sum;
}

int main(){
    // int inp = 21;
    int inp = 20;
    int ans = getFibOutput(inp);
    cout<<ans<<endl;
    return 0;
}
