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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> f(n + 1, vector<ll>(k + 1, (ll) (1e18)));
    f[0][0] = 0;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= k; j++) {
        int curr = a[i];
        for(int p = 0; p + j <= k && i + p < n; p++) {
          curr = min(curr, a[i + p]);
          f[i + p + 1][j + p] = min(f[i + p + 1][j + p], f[i][j] + 1LL * (p + 1) * curr);
        }
      }
    }

    cout << *min_element(f[n].begin(), f[n].end()) << '\n';
  }
  return 0;
}

