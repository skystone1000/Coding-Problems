// Codechef May Lunch time 2020
// B. Weird Walk - WWALK

#include<iostream>
#include<vector>
//#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        long long n ;
        cin >> n;
        long long  sum = 0;
        vector<long long> a(n);
        vector<long long> b(n);
        long long apos = 0, bpos = 0;
        long long wired = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            if (apos == bpos && a[i] == b[i]) {
                wired += a[i];
            }
            apos = apos + a[i];
            bpos = bpos + b[i];
        }
        cout << wired << endl;
        

    }
    return 0;
}