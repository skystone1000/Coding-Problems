#include<iostream>
#include<vector>
using namespace std;

int findLargest() {
    int largest;
    int secondLargest;
    vector<int> arr = {4, 11, 2, 35, 33, 9, 52, 45, 15};

    for(int i=0;i<arr.size();i++){
        if(i==0){
            largest = arr[i];
            secondLargest = arr[i];
        }
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}


int main(){
    
    int ans = findLargest();
    cout<<ans<<endl;

    return 0;
}
