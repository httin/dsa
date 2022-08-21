#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& in, vector<int>& ans, int l, int k) {
  if (k == 0) {
    cout << ans[0];
    for (int i=1; i<6; i++) cout << ' ' << ans[i];
    cout << '\n';
    return;
  }
  
  for (size_t i = l; i < in.size(); i++) {
    ans.push_back(in[i]);
    solve(in, ans, i+1, k-1);
    ans.pop_back();
  }
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, h;
    cin >> n >> h;
  
  }
   
  return 0;
}
