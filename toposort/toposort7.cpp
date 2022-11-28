#include <bits/stdc++.h>

using namespace std;

const int maxN = 100000;
vector<int> graph[maxN + 5];
array<int, maxN + 5> indeg;

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> p(m+1);

  for (int i=1; i<=m; i++)
    cin >> p[i];

  for (int i=1; i<=n-1; i++) {
    int u,v;
    cin >> u >> v;
    graph[u].push_back(v);
  }

  vector<int> res;
  queue<int> indeg;

  return 0;
}

