#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int maxN = 1000;

void dfs(int u, vector<int> graph[], vector<bool>& visited, vector<int>& res) {
  visited[u] = true;
  for (int v : graph[u]) {
    if (!visited[v])
      dfs(v, graph, visited, res);
  }
  res.push_back(u);
}

int main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int n, r;
    cin >> n >> r;

    vector<int> graph[maxN] = {vector<int>()};
    array<int, maxN> indeg = {0};

    for (int i=0; i<r; i++) {
      int u,v;
      cin >> u >> v;
      graph[v].push_back(u);
      indeg[u]++;
    }
    
    /// toposort
    vector<int> res;
    vector<bool> visited(n, false);
    for (int i=0; i<n; i++) {
      if (!visited[i])
        dfs(i, graph, visited, res);
    }
    reverse(res.begin(), res.end());
    
    assert((int)res.size() == n);
    
    vector<int> rank(n, 0);
    for (int i=0; i<n; i++) {
      int u = res[i];
      if (indeg[u] == 0) {
        rank[u] = 1;
      }
      for (int v : graph[u])
        rank[v] = max(rank[v], rank[u] + 1);
    }
    
    vector<pii> employees; // <rank, index>
    for (int i=0; i<n; i++)
      employees.push_back(pii(rank[i], i));
    sort(employees.begin(), employees.end());

    cout << "Scenario #" << t << ":\n";
    for (auto employee : employees) {
      cout << employee.first << ' ' << employee.second << '\n';
    }
  }
  return 0;
}
