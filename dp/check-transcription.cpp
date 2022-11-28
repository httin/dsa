#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vpii = vector<pii>;

int countBit(string& s, char bit) {
  int res=0;
  for (char& c : s)
  return res;
}

void solve() {
  string s, t;
  cin >> s >> t; // |s| = [2,1e5], |t| = [1,1e6]
  int no0 = countBit(s, '0');
  int no1 = countBit(s, '1');
  
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
