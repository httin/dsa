#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll sum=0, k;
    string n;
    cin >> k >> n;
    for (size_t i=0; i<n.length(); i++) {
      sum += n[i] - '0' + 0LL;
    }

    std::sort(n.begin(), n.end());
    if (sum >= k)
      cout << 0 << endl;
    else {
      ll need = k - sum;
      size_t ans=0;
      while (need > 0) {
        int cur = n[ans] - '0';
        need -= (9 - cur);
        ans++;
      }
      cout << ans << endl;
    }
    return 0;
}
