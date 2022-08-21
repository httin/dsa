#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int t,n,k; // t=[1,10] n=[1,500] k=[1,10]
  cin >> t;
  
  while (t-- > 0) {
    cin >> n >> k; 
    int a[500], res=k;
    for (int i=0; i<n; i++) { 
      string s;
      cin >> s;
      a[i] = std::stoi(s, 0, 2);
    }

    for (int mask=0; mask < (1<<k); mask++) {
      bool yes=true;
      for (int j=0; j<n; j++) {
        if (!(a[j] & mask)) {
          yes=false;
          break;
        }
      }
      if (yes) res = min(res, __builtin_popcount(mask));
    }
    cout << res << '\n';
  }
  
  return 0;
}
