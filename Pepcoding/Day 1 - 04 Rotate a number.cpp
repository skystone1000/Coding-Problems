#include <iostream>
#include<cmath>

using namespace std;
int main(){
    int n,k;
    cin>>n>>k;

    int num = 1;
    int temp = n;
    while(temp > 0){
        temp = temp / 10;
        num = num * 10;
    }
    
    while(k > 0){
        int digit = n % 10;
        n = n/10;
        cout<<"digit= "<<digit<<" n="<<n<<" k= "<<k<<endl;
        n = num * digit + n;
        k--;
    }
    cout<<n;

}