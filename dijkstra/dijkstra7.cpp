#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
#define MAX 100005
#define INF 1e9 + 7

int N, M, k, x;
vector<ii> graph[MAX];
int distA[MAX];
int distB[MAX];

struct comp {
  bool operator() (const ii& a, const ii& b) const {
    return a.second > b.second;
  }
};
void dijikstra(int s, int* dist) {
  std::priority_queue<ii, vector<ii>, comp> pq;
  pq.push(ii(s, 0));
  dist[s] = 0;
  
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
  cin >> N >> M >> k >> x;
  vector<int> kCities(k);
  for (int i = 0; i <= N; ++i) {
    distA[i] = distB[i] = INF;
  }
  for (int i = 0; i < k; ++i) {
    cin >> kCities[i];
  }
  for (int i = 0; i < M; ++i) {
    int u,v,w;
    cin >> u >> v >> w;
    graph[u].push_back(ii(v,w));
    graph[v].push_back(ii(u,w));
  }
  int A,B,res = INF;
  cin >> A >> B;
  dijikstra(A, distA);
  dijikstra(B, distB);
  for (int& city : kCities) {
    if (distB[city] <= x)
      res = min(res, distA[city] + distB[city]);
  }
  if (res < x)
    cout << res << endl;
  else
    cout << -1;
  
	return 0;
}
