#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int leak=0;
  double total=0, res=0, n=0, pivot=0, lastPivot=0;
  string s;

  while (true) {
    cin >> pivot >> s;

    total += ((double)n/100.0 + leak)*(pivot - lastPivot);
    res = max(res, total);
    lastPivot = pivot;

    if (s == "Fuel") {
      cin >> s >> n;
      if (n == 0) {
        return 0;
      }
    } else if (s == "Leak") {
      ++leak;
    } else if (s == "Mechanic") {
      leak = 0;
    } else if (s == "Gas") {
      cin >> s;
      total = 0;
    } else if (s == "Goal") {
      cout << fixed << setprecision(3) << res << endl;
      total = 0;
      res = 0;
      n = 0;
      leak = 0;
      lastPivot = 0;
    }
  }
  return 0;
}
