#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    bool zero = false;
    int n, k;
    cin >> n >> k;
    vector<int> neg, pos;

    for (int i=0; i<n; i++) {
      int num;
      cin >> num;
      if (num > 0) pos.push_back(num);
      else if (num < 0) neg.push_back(num);
      else zero = true;
    }

    sort(neg.begin(), neg.end());

    for (size_t i=0; i<neg.size() && k > 0; i++) {
      neg[i] *= -1;
      --k;
    }

    int sum=0;
    for (auto x : neg) sum += x;
    for (auto x : pos) sum += x;
    if (!(zero || k%2 == 0)) {
      int minabs = 1e4;
      for (auto x : neg) minabs = min(minabs, abs(x));
      for (auto x : pos) minabs = min(minabs, abs(x));
      sum -= 2*minabs;
    }
    cout << sum << endl;
    return 0;
}
