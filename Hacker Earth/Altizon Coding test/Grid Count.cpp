// Problem - Grid Count
// https://www.hackerearth.com/problem/algorithm/grid-count-1/

#include <bits/stdc++.h>
using namespace std;

map < long long , bool > p;
long long col [1000 + 10][1000 + 10];
long long row_col [1000 + 10][1000 + 10];

int main(){
    int n , k, ans = 0;
    
    // mark perfect cube numbers as true
    for(long long i = 1; i <= 10000; i++){
        p[i * i * i] = true;
    }

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> col[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
			// sum the elements in each row from the beginning to column (j).
            col[i][j] += col[i][j - 1];
			// sum the elements in the previous rows to the current row up to column (j).
            row_col[i][j] = row_col[i - 1][j] + col[i][j];      
        }
    }

    for(int i = k; i <= n; i++){
        for(int j = k; j <= n; j++){
			// inclusion and exclusion principle
            long long num = row_col[i][j] - row_col[i - k][j] - row_col[i][j - k] + row_col[i - k][j - k];
			// increase the answer if number if perfect cube
            if(p[num]) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}