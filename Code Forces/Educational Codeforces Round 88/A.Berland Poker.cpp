// Codeforces Educational Round 88
// A.Berland Poker
#include<iostream>
//#include <bits/stdc++.h>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        int n, m, k;
        cin >> n >> m >> k;
        if (m == 0) {
            cout << "0" << endl;
            continue;
        }
        if (n / k >= m) {
            cout << m << endl;
            continue;
        }
        else {
            int eachCards = n / k;
            if ((m - eachCards) % (k - 1) == 0) {
                int inter = (m - eachCards) / (k - 1);
                int points = eachCards - (inter);
                cout << points << endl;

            }
            else {
                int inter = (m - eachCards) / (k - 1);
                int points = eachCards - (inter) - 1;
                cout << points << endl;
            }
        }




    }
    return 0;
}