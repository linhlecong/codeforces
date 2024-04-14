#include <bits/stdc++.h>
using namespace std;
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

int t, n, c, d;
vector<int> b;

bool ok() {
	sort(b.begin(), b.end());
	vector<int> g(n * n, -1);
	g[0] = b[0];
	for(int i = 1; i < n * n; i++) {
		int row = i / n;
		int col = i % n;
		if (row > 0) g[i] = g[(row - 1) * n + col] + c;
		if (col > 0) {
			if(g[i] == -1) g[i] = g[row * n + (col - 1)] + d;
			else if(g[i] != g[row * n + (col - 1)] + d) return false;
		}
	}
	sort(g.begin(), g.end());
	for(int i = 0; i < n * n; i++) {
		if (g[i] != b[i]) return false;
	}
	return true;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> c >> d;
		b.resize(n * n);
		for(int i = 0; i < n * n; i++) cin >> b[i];
		cout << (ok() ? "YES" : "NO") << '\n';
	}
	return 0;
}

