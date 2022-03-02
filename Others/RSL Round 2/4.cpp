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
