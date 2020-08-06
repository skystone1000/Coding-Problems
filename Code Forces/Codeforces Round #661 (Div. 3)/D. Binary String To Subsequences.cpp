// Codeforces Round #661 (Div. 3) Editorial
// D. Binary String To Subsequences 
// https://codeforces.com/contest/1399/problem/D

/*

Let's iterate over all characters of s from left to right, maintaining two arrays pos0 and pos1, 
where pos0 stores indices of all subsequences which end with '0' and pos1 stores indices of all 
subsequences which end with '1'. If we met '0', then the best choice is to append it to some existing 
subsequence which ends with '1'. If there are no such sequences, we need to create new one which ends with '0'.
Otherwise we need to convert one of '1'-sequences to '0'-sequence. The same works with characters '1'. 
So, when we don't need to create the new sequence, we try to don't do that. And values in arrays pos0 and 
pos1 help us to determine the number of sequence we assign to each character. And also, there is a cute 
proof of this solution from Gassa: let f(i) be the difference between the number of '1' and the number 
of '0' on the prefix of s of length i. We claim that the answer is max(f(i))−min(f(i)) and let's show 
why is it true. Let's build a function on a plane with points (i,f(i)). Then we can match each x between 
min(f(i)) and max(f(i)) with some subsequence.

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
		string s;
		cin >> n >> s;
		vector<int> ans(n);
		vector<int> pos0, pos1;
		for (int i = 0; i < n; ++i) {
			int newpos = pos0.size() + pos1.size();
			if (s[i] == '0') {
				if (pos1.empty()) {
					pos0.push_back(newpos);
				} else {
					newpos = pos1.back();
					pos1.pop_back();
					pos0.push_back(newpos);
				}
			} else {
				if (pos0.empty()) {
					pos1.push_back(newpos);
				} else {
					newpos = pos0.back();
					pos0.pop_back();
					pos1.push_back(newpos);
				}
			}
			ans[i] = newpos;
		}
		cout << pos0.size() + pos1.size() << endl;
		for (auto it : ans) cout << it + 1 << " ";
		cout << endl;
	}
	
	return 0;
}