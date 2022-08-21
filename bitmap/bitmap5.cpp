#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxN = 200000;
array<ll,2> a[maxN + 5];

int main() {
  int t,n;
  cin >> t;

  while (t-- > 0) {
    cin >> n;
    ll ans=0;
    for (int i=1; i<=n; i++) {
      cin >> a[i][0];
      a[i][1] = 1LL*i*(n - i + 1)%2;
      ans ^= (a[i][0] * a[i][1]);
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}
 
