#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
#define MAX 505
#define INF 1e9 + 7

int N, M, S, D;
vector<ii> graphS[MAX];
vector<ii> graphD[MAX];
vector<ii> graph[MAX];
int distS[MAX];
int distD[MAX];
int dist[MAX];

void dijikstra(int s, int* dist, vector<ii> _graph[]) {
  std::priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push(ii(0, s));
  dist[s] = 0;
  
  while (!pq.empty()) {
    int w = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    for(auto& node : _graph[u]) {
      int cost = node.first;
      int v = node.second;
      if (dist[v] > w + cost) {
        dist[v] = w + cost;
        pq.push(ii(dist[v], v));
      }
    }
  }
}

void reset() {
    for (int i = 0; i < N; ++i) {
      distS[i] = distD[i] = dist[i] = INF;
      graphS[i].clear();
      graphD[i].clear();
      graph[i].clear();
    }
}

int main() 
{
  while(true)
  {
    scanf("%d%d", &N, &M);
    if (N == 0 && M == 0)
      break;
    scanf("%d%d", &S, &D);
    reset();
    for (int i = 0; i < M; ++i) {
      int u,v,w;
      scanf("%d%d%d", &u, &v, &w);
      graphS[u].push_back(ii(w,v));
      graphD[v].push_back(ii(w,u));
    }
    
    dijikstra(S, distS, graphS);
    dijikstra(D, distD, graphD);
    int shortestLen = distS[D];
    for (int u = 0; u < N; ++u) {
      for (auto& node : graphS[u]) {
        int v = node.second;
        int w = node.first;
        if (distS[u] + distD[v] + w != shortestLen) {
          graph[u].push_back(ii(w,v));
        }
      }
    }
    dijikstra(S, dist, graph);
    printf("%d\n", (dist[D] == INF) ? -1 : dist[D]);
  }
	return 0;
}
