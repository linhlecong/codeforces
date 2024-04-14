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
		int n, m, k; cin >> n >> m >> k;
		vector<int> a(n);
		multiset<int> match, notMatch, sb;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) {
			int x; cin >> x;
			sb.insert(x);
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if (i < m - 1) {
				if (sb.find(a[i]) != sb.end()) {
					match.insert(a[i]);
					sb.erase(sb.find(a[i]));
				} else {
					notMatch.insert(a[i]);
				}
			} else {
				int l = i - m + 1;
				if (l > 0) {
					if (match.find(a[l - 1]) != match.end()) {
						if (notMatch.find(a[l - 1]) != notMatch.end()) {
							notMatch.erase(notMatch.find(a[l - 1]));
						} else {
							match.erase(match.find(a[l - 1]));
							sb.insert(a[l - 1]);
						}
					} else {
						notMatch.erase(notMatch.find(a[l - 1]));
					}
				}
				if (sb.find(a[i]) != sb.end()) {
					match.insert(a[i]);
					sb.erase(sb.find(a[i]));
				} else {
					notMatch.insert(a[i]);
				}
				if ((int) match.size() >= k) ++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

