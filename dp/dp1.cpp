#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<ll, ll> mp;

ll dp(ll n) {
  if (mp.find(n) != mp.end())
    return mp[n];
  if (n <= 5) {
    mp[n] = n;
    return n;
  }
  ll res = max(n, dp(n/2) + dp(n/3) + dp(n/4));
  mp[n] = res;
  return res;
}

int main() {
  ll n;
  while (cin >> n) {
    cout << dp(n) << endl;
  }
  return 0;
}
