// Codechef May Lunch time 2020
// C. Convert the String - CONVSTR

// NOT COMPLETE

#include<iostream>
#include<vector>
#include<set>
//#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        long long n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        set<char> aChars;
        set<char> bChars;

        int fa=0, fb=0;
        vector<int> aBset;
        vector<int> bBset;
        for (int i = 0; i < n; i++) {
            aChars.insert(a[i]);
            if (fa == 0 && a[i] == 'a') {
                fa = i;
            }
            if (fb == 0 && a[i] == 'b') {
                fb = i;
            }


            bChars.insert(b[i]);
            if (b[i] == 'a') {
                aBset.push_back(i);
            }
            if (b[i] == 'b') {
                bBset.push_back(i);
            }
        }

        int flag = 0;
        for (char toCheck : bChars) {
            auto it = aChars.find(toCheck);
            if (it == aChars.end()) {
                cout << "-1\n";
                flag = 1;
                break;
            }
            else {
                continue;
            }
        }
        if (flag == 1) {
            continue;
        }

        cout << 2 << endl;
        cout << aBset.size();
        for (auto x : aBset) {
            cout << " " << x;
        }
        cout << endl;
        cout << bBset.size();
        for (auto x : bBset) {
            cout << " " << x;
        }

        cout << endl;

        





    }
    return 0;
}