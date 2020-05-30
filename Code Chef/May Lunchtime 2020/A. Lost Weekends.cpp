// Codechef May Lunch time 2020
// A. Lost Weekends - LOSTWKND

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
        int n=5;
        int sum=0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int p;
        cin >> p;
        for (int i = 0; i < n; i++) {
            a[i] = a[i] * p;
            sum += a[i];
        }

        if (sum <= 24 * 5) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }


    }
    return 0;
}