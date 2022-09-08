/*
A-5​: ​Write a function that takes an array of numbers as input parameter and prints the numbers 
that have remainder of 4 when divided by 5.

Example:
Input: [19,10,44,3,11,129] Output: 19 44 129
Input: [13,4] Output: 4
*/


#include<iostream>
#include<vector>

using namespace std;

void Func(vector<int> &arr) {
    for(auto ele:arr){
        if(ele % 5 == 4){
            cout<<ele<<" ";
        }
    }
}

int main(){
    vector<int> arr = {13,4};
    Func(arr);
    return 0;
}
