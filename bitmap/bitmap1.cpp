#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxN = 100000;
int pref0[maxN + 1];
int pref1[maxN + 1];

int main() {
  int n,q,l,r;
  cin >> n;
  for (int x, i = 1; i <= n; i++) {
    cin >> x;
    pref0[i] = pref0[i-1] + !x;
    pref1[i] = pref1[i-1] + x;
  }
  
  cin >> q;
  while (q-- > 0) {
    cin >> l >> r;
    int c1 = (pref1[r] - pref1[l-1])%2;
    int c2 = pref0[r] - pref0[l-1];
    cout << c1 << ' '  << c2 << '\n';
  }
  
  return 0;
}
