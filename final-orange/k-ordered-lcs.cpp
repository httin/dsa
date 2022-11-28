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

array<int, 2000> an;
array<int, 2000> am;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));

  for (int i=0; i<n; i++) cin >> an[i];
  for (int i=0; i<m; i++) cin >> am[i];

  
  for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
      if (an[i - 1] == am[j - 1])
        dp[i][j][0] = dp[i-1][j-1][0] + 1;
      else
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]);
  

  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      for (int z=1; z<=k; z++)
        if (an[i-1] == am[j-1]) {
          dp[i][j][z] = max({
            dp[i-1][j][z],
            dp[i][j-1][z],
            dp[i-1][j-1][z] + 1
          });
        } else {
          dp[i][j][z] = max({
            dp[i-1][j][z],
            dp[i][j-1][z],
            dp[i-1][j-1][z-1] + 1
          });
        }

  cout << dp[n][m][k] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
