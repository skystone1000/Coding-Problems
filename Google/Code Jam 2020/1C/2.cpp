#include <bits/stdc++.h>
using namespace std;

int Calc(int x, int y, string m) {
    int n = m.length();
    int z;
    for (int i = 0; i < n; i++) 
    {
        if (m[i] == 'N') 
        {
            y = y + 1;
            z = abs(x) + abs(y);
        } 
        else if (m[i] == 'E') 
        {
            x = x + 1;
            z = abs(x) + abs(y);
        } 
        else if (m[i] == 'S') 
        {
            y = y - 1;
            z = abs(x) + abs(y);
        } 
        else if (m[i] == 'W') 
        {
            x = x - 1;
            z = abs(x) + abs(y);
        }
        
        if (z <= (i + 1)) 
        {
            return (i + 1);
        }
    }
    return -1;
}

int main() {
    int cas;
    cin >> cas;
    
    for (int t = 0; t < cas; t++) 
    {
        int x, y;
        cin>>x>>y;
        string m;
        cin >> m;
        cout << "Case #" << t << ": ";
        
        int ans;
        ans = Calc(x,y,m);

        if (-1 == ans) 
        {
            cout << "IMPOSSIBLE"<<endl;
        } 
        else 
        {
            cout << ans<<endl;
        }
    }
}