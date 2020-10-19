#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }



void test_case() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	sort(a.begin(), a.end());
	long long best_answer = LONG_LONG_MAX;
	int L = 0, R = 0;
	long long current = 0;
	for(int i = 1; i < n; ++i) {
		current += k - a[i];
	}
	int cnt_minus = 0;
	debug() << imie(current);
	for(int me = 0; me < n; ++me) {
		if(me != 0) {
			current -= a[me];
			cnt_minus--;
		}
		while(R + 1 < n && a[R+1] - a[me] <= k / 2) {
			++R;
			current -= k - a[R];
			current += a[R];
			cnt_minus++;
		}
		while(a[me] - a[L] > k / 2) {
			current -= -a[L];
			current += k + a[L];
			cnt_minus++;
			++L;
		}
		long long maybe = current + (long long) (n - 1 - 2 * cnt_minus) * a[me];
		debug() << imie(L) imie(me) imie(R) imie(current) imie(cnt_minus) imie(maybe);
		best_answer = min(best_answer, maybe);
		current += -a[me];
		// cnt_minus++;
	}
	printf("%lld\n", best_answer);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
