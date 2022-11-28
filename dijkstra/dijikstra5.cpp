#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
#define MAX 20005
#define INF 1e9 + 7

int N, M, S, F;
vector<ii> graph[MAX];
long long dist[MAX];

struct comp {
  bool operator() (const ii& a, const ii& b) const {
    return a.second > b.second;
  }
};
void dijikstra(int s, int f) {
  std::priority_queue<ii, vector<ii>, comp> pq;
  dist[s] = 0;
  pq.push(ii(s, 0));
  
  while (!pq.empty()) {
    ii node = pq.top();
    pq.pop();
    int u = node.first;
    int w = node.second;
    if (dist[u] < w)
      continue;
      
    for (int i = 0; i < (int)graph[u].size(); ++i) {
      int v = graph[u][i].first;
      int cost = graph[u][i].second;
      // printf("(%d,%d)->%d: %d\n",u,w,v,cost);
      if (dist[v] > w + cost) {
        dist[v] = w + cost;
        pq.push(ii(v, dist[v]));
      }
    }
  }
}

int main() 
{
  int T;
  cin >> T;
  
  for (int t = 1; t <= T; ++t)
  {
    cin >> N >> M >> S >> F;
    for (int i = 0; i < N; ++i) {
      graph[i].clear();
      dist[i] = INF;      
    }
    
    for (int i = 0; i < M; ++i) {
      int u,v,w;
      cin >> u >> v >> w;
      graph[u].push_back(ii(v,w));
      graph[v].push_back(ii(u,w));
    }
    
    dijikstra(S, F);
    
    if (dist[F] != INF)
      printf("Case #%d: %lld\n", t, dist[F]);
    else
      printf("Case #%d: unreachable\n", t);
  }
	return 0;
}
