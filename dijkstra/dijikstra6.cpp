#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
#define MAX 100
#define INF 1e9 + 7

int N, R;
vector<int> graph[MAX];
int distS[MAX];
int distD[MAX];

void dijikstra(int s, int* dist) {
  std::priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push(ii(0, s));
  dist[s] = 0;
  
  while (!pq.empty()) {
    int w = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    for(auto& v : graph[u]) {
      if (dist[v] > w + 1) {
        dist[v] = w + 1;
        pq.push(ii(dist[v], v));
      }
    }
  }
}

int main() 
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
  {
    scanf("%d%d", &N, &R);
    for (int i = 0; i < N; ++i) {
      distS[i] = distD[i] = INF;
      graph[i].clear();
    }

    int u,v,s,d;
    for (int i = 0; i < R; ++i) {
      scanf("%d%d", &u, &v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    scanf("%d%d", &s, &d);
    
    dijikstra(s, distS);
    dijikstra(d, distD);
    int res = 0;
    for (int i = 0; i < N; ++i) {
      res = max(res, distS[i] + distD[i]);
    }
    printf("Case %d: %d\n", t, res);
  }
  
	return 0;
}
