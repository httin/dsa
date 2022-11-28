#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline int toInt(char c) {
  return c - '0';
}

int main() {
  string in;
  while (true) {
    cin >> in;
    if (in == "0") 
      break;

    int n = in.length();
    
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    
    vector<ll> dp(n+1, 0);
    dp[0] = 1; // in[-1]
    dp[1] = 1; // in[0]
    for (int i=1; i<n; i++) {
      if (in[i] != '0')
        dp[i + 1] = dp[i];

      if (in[i - 1] != '0') {
        int val = toInt(in[i - 1])*10 + toInt(in[i]);
        if (val <= 26)
          dp[i + 1] += dp[i - 1];
      }
    }
    cout << dp[n] << '\n';
  }
  return 0;
}
