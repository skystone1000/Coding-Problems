// TCS Digital
// Contained 2 Questions 
// 01 COmpare petrol and dielsel prices

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>
#include<cmath>
#include<unordered_map>

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll distance1,fuel1,showroom1,run1,maintain1;
    ll distance2,fuel2,showroom2,run2,maintain2;

    cin>>distance1>>fuel1>>showroom1>>run1>>maintain1;
    cin>>distance2>>fuel2>>showroom2>>run2>>maintain2;

    ll fuelCost1 = (60 * run1 * fuel1 )/ distance1;
    ll cost1 = showroom1 + (maintain1 * 60) + fuelCost1;

    ll fuelCost2 = (60 * run2 * fuel2 )/ distance2;
    ll cost2 = showroom2 + (maintain2 * 60) + fuelCost2;

    // deb2(cost1, cost2);
    if(cost1 < cost2)
        cout<<"petrol"<<endl;
    else
        cout<<"diesle"<<endl;

    return 0;
}