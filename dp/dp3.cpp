#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll n;

  while (cin >> n) {
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for (int i=1; i*i*i < 10000; i++) {
      int coin = i*i*i;
      for (int j = coin; j <= n; j++) {
        dp[j] += dp[j - coin];
      }
    }
    cout << dp[n] << '\n';
  }
  
  return 0;
}
