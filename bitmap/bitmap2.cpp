#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int t;
  ll n, m;
  cin >> t;
  while (t-- > 0) {
    cin >> n >> m; // [1, 1e16]
    vector<int> exp;
    while (m > 0) {
      ll i = 0, j = 1;
      while (2*j <= m) {
        ++i;
        j *= 2;
      }
      exp.push_back(i);
      m -= j;
    }
    
    vector<string> ans;
    for (int e : exp) {
      string s = "(" + std::to_string(n) + "<<" + std::to_string(e) + ")";
      ans.push_back(s);
    }
    cout << std::accumulate(ans.begin() + 1, ans.end(), ans[0], [](string a, string b) {
      return a + " + " + b;
    }) << '\n';
  }

  return 0;
}
