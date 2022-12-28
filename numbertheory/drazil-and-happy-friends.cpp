#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;


int main() 
{
  int n, m;
  cin >> n >> m; // [1,100]
  vector<int> res(m+n, 0);
  vector<int> b(n, 0);
  vector<int> g(m, 0);
  int x;
  cin >> x;
  for (int r,i=0; i<x; i++) {
    cin >> r;
    b[r] = 1, g[r%m] = 1;
    for (int j=0; j<m; j++) {
      if (j%n == r)
        g[j] = 1;
    }
  }
  cin >> x;
  for (int r,i=0; i<x; i++) {
    cin >> r;
    g[r]
  }
  
  return 0;
}
