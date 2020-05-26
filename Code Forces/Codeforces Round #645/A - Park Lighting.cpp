// Codeforces round 645
// Problem A - Park Lighting
#include<iostream>

//#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        int r, c;
        cin >> r >> c;
        long long lamps = 0;
        if (c % 2 == 0) {
            lamps = r * c / 2;
        }
        else {
            if (r % 2 == 0) {
                lamps = (r * (c - 1) / 2) + r / 2;
            }
            else {
                lamps = (r * (c - 1) / 2) + ((r - 1) / 2) + 1;
            }
        }
        cout << lamps << endl;

    }
    return 0;
}