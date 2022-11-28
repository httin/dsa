#include <bits/stdc++.h>

using namespace std;

int main() {
  int t=0;
  int n, m;
  while (cin >> n) {
    t++;
    map<string, int> mp;
    vector<string> name(n);
    for (int i=0; i<n; i++) {
      cin >> name[i];
      mp[name[i]] = i;
    }

    cin >> m;
    vector<vector<int>> graph(n, vector<int>());
    for (int i=0; i<m; i++) {
      string d1, d2;
      cin >> d1 >> d2;
      int u = mp[d1];
      int v = mp[d2];
      graph[u].push_back(v);
    }
    
    vector<int> result;
    vector<int> indeg(n+1, 0);
    priority_queue<int, vector<int>, std::greater<int>> minheap;
    
    for (int u=0; u<n; u++)
      for (int v: graph[u])
        indeg[v]++;
    
    for (int u=0; u<n; u++)
      if (indeg[u] == 0)
        minheap.push(u);

    while(!minheap.empty()) {
      int u = minheap.top();
      minheap.pop();
      result.push_back(u);
      for (int v: graph[u]) {
        indeg[v]--;
        if (indeg[v] == 0)
          minheap.push(v);
      }
    }

    printf("Case #%d: Dilbert should drink beverages in this order:", t);
    for (int u: result)
      printf(" %s", name[u].data());
    cout << ".\n";
  }
  return 0;
}
