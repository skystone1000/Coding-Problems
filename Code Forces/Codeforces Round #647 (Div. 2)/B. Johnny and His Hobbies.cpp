// Codeforces Round #647 (Div. 2) - Thanks, Algo Muse!
// B. Johnny and His Hobbies

#include<iostream>
#include<set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;
    for (int t = 0; t < testCases; t++) {
        int n;
        cin >> n;
        set<int> s;
        
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            s.insert(temp);
        }

        int ans = -1;

        for (int k = 1; k < 2000; k++) {
            set<int> sNew;
            for (int element : s) {
                int newElement = element ^ k;
                sNew.insert(newElement);
            }
            if (s == sNew) {
                ans = k;
                break;
            }

        }

        cout << ans << endl;
        //cout << "============\n";




    }
    return 0;
}