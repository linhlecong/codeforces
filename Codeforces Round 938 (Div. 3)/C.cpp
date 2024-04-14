#include <bits/stdc++.h>
using namespace std;
#define ll long long

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main() {
	int t; cin >> t;
	while (t--) {
		int n; ll k; cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int l = 0, r = n - 1, ans = 0;
		while (l < r && k > 0) {
			int x = min(a[l], a[r]);
			a[l] -= (x - 1);
			a[r] -= (x - 1);
			k -= 2 * (x - 1);
			if (k < 0) break;
			if (k > 0) {
				--a[l];
				--k;
				if (a[l] == 0) {
					++ans;
					++l;
				}
			}
			if (k > 0) {
				--a[r];
				--k;
				if (a[r] == 0) {
					++ans;
					--r;
				}
			}
		}
		if (l == r && k >= a[l]) ++ans;
		cout << ans << '\n';
	}
	return 0;
}

