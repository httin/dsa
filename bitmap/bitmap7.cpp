#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int maxN = 100000;

array<vector<int>, 100005> graph;
array<int, 100005> target;
array<int, 100005> check;
vector<int> result;
bool cycle = false;

void dfs(int u) {
  if (check[u] == 0) {
    check[u] = 1;
    for (int v : graph[u]) {
      dfs(v);
    }
    check[u] = 2; // pass
    result.push_back(u);
  } else if (check[u] == 1) {
    cycle = true;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i=1; i<=k; i++)
    cin >> target[i];
  for (int i=1, num; i<=n; i++) {
    cin >> num;
    for (int j=1; j<=num; j++) {
      int v;
      cin >> v;
      graph[i].push_back(v);
    }
  }
  
  for (int u=1; u<=k; u++) {
    //cout << "target=" << target[u] << "; check=" << check[u] << endl;
    if (check[target[u]] == 0) dfs(target[u]);
    if (cycle) break;
  }

  if (cycle)
    cout << -1 << endl;
  else
  {
    cout << result.size() << '\n';
    for (auto it = result.begin(); it < result.end(); it++)
      cout << *it << ' ';
    cout << endl;
  }
  
  return 0;
}
