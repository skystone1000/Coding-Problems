// Pepcoding
// Ques - https://www.pepcoding.com/resources/online-java-foundation/getting-started/rotate-a-number-official/ojquestion
// Soln - 

#include <iostream>
#include<cmath>

using namespace std;
int main(){
    // Input
    int n,k;
    cin>>n>>k;

    // Calculating total digits
    int digits = 0;
    int temp = n;
    while(temp > 0){
        temp = temp / 10;
        digits++;
    }
    
    // For K greater than total digits
    k = k % digits;
    
    // For -ve K values => 
    // (+K = TotalDigits - [-K]) 
    // (+2 = -4)
    if(k < 0){
        k = k * -1;
        k = digits - k;
    }
    
    // Splitting the number at K digits
    int divisor = pow(10,k);
    int rem = n % divisor;
    int quo = n / divisor;
    
    // Creating new number
    int multiplier = pow(10, digits-k);
    int ans = rem * multiplier + quo;
    cout<<ans;
}