#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n+1, vector<int>());
  for (int u,v,i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }
  
  vector<int> result;
  vector<int> indeg(n+1, 0);
  priority_queue<int, std::vector<int>, std::greater<int>> zero_indeg;

  for (int u = 1; u <= n; ++u) {
    for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
      indeg[*it]++;
    }
  }

  for (int u = 1; u <= n; ++u) {
    if (indeg[u] == 0)
      zero_indeg.push(u);
  }

  while(!zero_indeg.empty()) {
    int u = zero_indeg.top();
    zero_indeg.pop();
    result.push_back(u);

    for (int v : graph[u]) {
      indeg[v]--;
      if (indeg[v] == 0)
        zero_indeg.push(v);
    }
  }

  for (int u = 1; u <= n; u++)
    if (indeg[u] != 0) {
      cout << "Sandro fails." << endl;
      return 0;
    }
  
  for (int i: result)
    cout << i << ' ';
  cout << endl;
  return 0;
}
