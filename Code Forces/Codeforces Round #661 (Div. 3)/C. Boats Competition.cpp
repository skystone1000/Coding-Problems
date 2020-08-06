// Codeforces Round #661 (Div. 3) Editorial
// C. Boats Competition
// https://codeforces.com/contest/1399/problem/C

/*

This is just an implementation problem. Firstly, let's fix s (it can be in range [2;2n]), 
find the maximum number of boats we can obtain with this s and choose the maximum among all found values.
To find the number of pairs, let's iterate over the smallest weight in the team in range [1;⌊s+12⌋−1]. 
Let this weight be i. Then (because the sum of weights is s) the biggest weight is s−i. 
And the number of pairs we can obtain with such two weights and the total weight s is min(cnti,cnts−i), 
where cnti is the number of occurrences of i in w. And the additional case: if s is even, 
we need to add ⌊cnts22⌋. Don't forget that there is a case s−i>n, so you need to assume that these 
values cnt are zeros.

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> cnt(n + 1);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			++cnt[x];
		}
		int ans = 0;
		for (int s = 2; s <= 2 * n; ++s) {
			int cur = 0;
			for (int i = 1; i < (s + 1) / 2; ++i) {
				if (s - i > n) continue;
				cur += min(cnt[i], cnt[s - i]);
			}
			if (s % 2 == 0) cur += cnt[s / 2] / 2;
			ans = max(ans, cur);
		}
		cout << ans << endl;
	}
	
	return 0;
}