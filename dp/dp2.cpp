#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  
  if (n == 1) {
    cout << k << endl;
    return 0;
  }
  vector<ll> end0(n+1, 0);
  vector<ll> endnot0(n+1, 0);
  
  endnot0[1] = k-1;
  for (int i=2; i<=n; i++) {
    endnot0[i] = (endnot0[i-1] + end0[i-1]) * (k - 1);
    end0[i] = endnot0[i-1];
  }
  
  cout << end0[n] + endnot0[n] << endl;
  return 0;
}
