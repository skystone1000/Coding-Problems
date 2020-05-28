// Codeforces Educational Round 88
// B.New Theatre Square

#include<iostream>

using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, x, y, ans = 0, i;
		cin >> n >> m >> x >> y;
		int pair = 2 * x;
		while (n--) {
			string s;
			cin >> s;
			for (i = 0; i < m; i++) {
				if (s[i] == '.' && s[i + 1] == '.' && pair > y) {
					ans += y;
					s[i + 1] = '*';
				}
				else if (s[i] == '.')
					ans += x;
			}
		}
		cout << ans << endl;
	}
}