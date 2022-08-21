#include <bits/stdc++.h>

using namespace std;

const int maxN = 100000;
vector<int> graph[maxN + 5];
array<int, maxN + 5> indeg;

int main() {
  int n, k;
  cin >> n >> k;
  for (int w, u=1; u <= k; u++) {
    cin >> w;
    for (int v, i=1; i <= w; i++) {
      cin >> v;
      graph[u].push_back(v);
    }
  }
  
  vector<int> toposort;
  queue<int> zero_indeg;

  for (int u = 1; u <= n; ++u)
    for (int v : graph[u]) 
      indeg[v]++;

  for (int u = 1; u <= n; ++u)
    if (indeg[u] == 0)
      zero_indeg.push(u);

  while(!zero_indeg.empty()) {
    int u = zero_indeg.front();
    zero_indeg.pop();
    toposort.push_back(u);

    for (int v : graph[u]) {
      indeg[v]--;
      if (indeg[v] == 0)
        zero_indeg.push(v);
    }
  }
  
  assert((int)toposort.size() == n);

  vector<int> res(n+1);

  res[toposort[0]] = 0;
  for (int i=1; i<n; i++)
    res[toposort[i]] = toposort[i-1];
  
  for (int i=1; i<=n; i++)
    cout << res[i] << '\n';
  return 0;
}
