#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    map<int, int> numbers;
    int sum = 0;
    int largest = INT_MIN;
    int smallest = INT_MAX;

    // Input values
    cout<<"Enter total values: ";
    cin>>n;
    cout<<"Enter array values: ";
    for(int i=0;i<n;i++){
        int curr;
        cin>>curr;
        sum += curr;
        numbers[curr]++;

        if(curr > largest)
            largest = curr;
        if(curr < smallest)
            smallest = curr;
    }

    // Output Required things
    cout<<"Sum: "<<sum<<endl;

    double tempSum = sum;
    cout<<"Average: "<<tempSum/n<<endl;

    cout<<"Largest: "<<largest<<endl;
    cout<<"Smallest: "<<smallest<<endl;
    
    // Calculation for most frequesnt
    int currMax = 0;
    int numMax = 0;
    for(auto ele:numbers){
        if(currMax < ele.second){
            currMax = ele.second;
            numMax = ele.first;
        }
    }

    cout<<"Most Frequest: "<<numMax<<endl;
    return 0;

}