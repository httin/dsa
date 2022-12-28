#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
      int n;
      vector<array<int,2>> supply;
      vector<array<int,2>> demand;

      cin >> n;
      if (n == 0) break;

      for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        if (num > 0)
          supply.push_back({i,num});
        else if (num < 0)
          demand.push_back({i,-num});
      }

      ll cost=0;
      size_t i=0, j=0;
      while (i < supply.size() && j < demand.size()) {
        array<int,2> a = supply[i];
        array<int,2> b = demand[j];
        if (a[1] > b[1]) {
          supply[i][1] -= b[1];
          demand[j][1] = 0;
          cost += abs(a[0] - b[0])*b[1]*1LL;
          j++;
        } else if (b[1] > a[1]) {
          supply[i][1] = 0;
          demand[j][1] -= a[1];
          cost += abs(a[0] - b[0])*a[1]*1LL;
          i++;
        } else {
          supply[i][1] = 0;
          demand[j][1] = 0;
          cost += abs(a[0] - b[0])*a[1]*1LL;
          i++;
          j++;
        }
      }

      cout << cost << '\n';
    }
    return 0;
}
