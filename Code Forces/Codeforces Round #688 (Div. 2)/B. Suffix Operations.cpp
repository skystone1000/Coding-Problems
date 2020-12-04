// Codeforces Round #688 (Div. 2) 
// B. Suffix Operations
// https://codeforces.com/contest/1453/problem/B

#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
ll ans,t,n,a[202020],i,j,k,m,sum,big;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ans=sum=big=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)scanf("%lld",&a[i]);
        for(i=1;i<n;i++)sum=sum+abs(a[i]-a[i-1]);
        big=max(abs(a[1]-a[0]),abs(a[n-1]-a[n-2]));
        for(i=1;i<n-1;i++)
            big=max(big,abs(a[i]-a[i-1])+abs(a[i+1]-a[i])-abs(a[i+1]-a[i-1]));
        sum=sum-big;
        ans=sum;
        printf("%lld\n",ans);
    }
    return 0;
}