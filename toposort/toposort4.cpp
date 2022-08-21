#include <bits/stdc++.h>

using namespace std;

using pii = pair<int,int>

const int maxN = 100005;
vector<int> graph[maxN];
array<int, maxN> indeg;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  pii start, end;
  cin >> start.first >> start.second >> end.first >> end.second; // [1,1e9]
  int n;
  cin >> n; // [1,1e5]
  
  for (int i=1; i<=n; i++) {
    int r,a,b;
    cin >> r >> a >> b;
  }
    
  for (int u=0; u<maxN; u++)
    for (int v : graph[u])
      indeg[v]++;
  
  queue<int> zero;
  vector<int> res;
  
  for (int u=0; u<maxN; u++)
    if (indeg[u] == 0) zero.push(u);

  while (!zero.empty()) {
    int u = zero.front();
    zero.pop();
    res.push_back(u);
    
    for (int v : graph[u]) {
      indeg[v]--;
      if (indeg[v] == 0)
        zero.push(v);
    }
  }
  
  cout << endl;  
  return 0;
}
