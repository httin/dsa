#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vpii = vector<pii>;

int topdown(string& s, vector<vi>& dp, int left, int right, int& n) {
  if (left >= right || left < 0 || right > n - 1) {
    return 0;
  }

  if (dp[left][right] != -1)
    return dp[left][right];

  if (s[left] == s[right]) {
    dp[left][right] = topdown(s, dp, left+1, right-1, n);
  } else {
    dp[left][right] = 1 + min(topdown(s, dp, left, right-1, n),
                              topdown(s, dp, left+1, right, n));
  }
  return dp[left][right];
}

void solve() {
  string s;
  cin >> s; // s.length <= 6100
  int n = s.length();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  cout << topdown(s, dp, 0, n-1, n) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
      solve();
    return 0;
}
