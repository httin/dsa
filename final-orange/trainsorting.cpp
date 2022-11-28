#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vpii = vector<pii>;
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define lb lower_bound
#define ub upper_bound
  
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)
 
const int dr[4] = {1,0,-1,0};
const int dc[4] = {0,1,0,-1};
const int MOD = 1e9+7;
const ll INF = 1e18; // not too close to LLONG_MAX
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<typename T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int a[2005];

void solve() {
  int n;
  cin >> n;

  vector<int> dp1(n, 1);
  vector<int> dp2(n, 1);
  vector<int> path1(n, -1);
  vector<int> path2(n, -1);
  
  if (n == 0) {
    cout << "0\n";
    return;
  }
  for (int i=0; i<n; i++)
    cin >> a[i];
  
  int encm = 0, enci1, enci2;
  for (int i=1; i<n; i++)
    for (int j=0; j<i; j++)
      if (a[i] > a[j] && dp1[i] < dp1[j] + 1) {
        dp1[i] = dp1[j] + 1;
        path1[i] = j;
        encm = max(encm, dp1[i]);
      }
  
  for (int i=0; i<n; i++) {
    if (path1[i] == -1) enci1 = i;
    
    if (
  }

  int decm = 0;
  for (int i=1; i<n; i++)
    for (int j=0; j<i; j++)
      if (a[i] < a[j] && dp2[i] < dp2[j] + 1) {
        dp2[i] = dp2[j] + 1;
        path2[i] = j;
        decm = max(decm, dp2[i]);
      }

  cout << encm << ' ' << decm << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
      solve();
    return 0;
}
