// Codeforces Round #647 (Div. 2) - Thanks, Algo Muse!
// A. Johnny and Ancient Computer

#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        long long a, b,div;
        long long count = 0, c8 = 0, c4 = 0, c2 = 0;
        cin >> a >> b;
        if (a == b) {
            cout << "0" << endl;
            continue;
        }
        if (b > a) {
            if (b % a != 0) {
                cout << "-1"<<endl;
                continue;
            }
            div = b / a;
        }
        else {
            if (a % b != 0) {
                cout << "-1" << endl;
                continue;
            }
            div = a / b;
        }

        while (div % 2 == 0) {
            count++;
            div = div / 2;
        }

        if (div != 1) {
            cout << "-1" << endl;
            continue;
        }

        if (count % 3 == 0) {
            cout << count / 3 << endl;
        }
        else {
            cout << (count / 3) + 1 << endl;
        }




    }
    return 0;
}