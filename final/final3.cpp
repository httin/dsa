#include <bits/stdc++.h>

using namespace std;
#define MAX 50005
int parent[MAX];
int ranks[MAX];

int N, M;
int ans;
void makeSet() {
  for (int i = 0; i <= N; ++i) {
    parent[i] = i;
    ranks[i] = 1;
  }
  ans = N;
}
int findSet(int u)
{
  if (u != parent[u])
    parent[u] = findSet(parent[u]);
  return parent[u];
}
void union_set(int u, int v) {
  int pu = findSet(u);
  int pv = findSet(v);
  if (pu != pv) {
    if (ranks[pu] > ranks[pv]) {
      parent[pv] = pu;
      ranks[pu] += ranks[pv];
    } else {
      parent[pu] = pv;
      ranks[pv] += ranks[pu];
    }
    ans--;
  }
}

int main()
{
  int t = 1;
  while (true)
  {
    cin >> N >> M;
    if (N == 0 && M == 0)
		  break;
    makeSet();
    for (int i = 0; i < M; ++i) {
      int u,v;
      cin >> u >> v;
      union_set(u, v);
    }
    
    printf("Case %d: %d\n", t, ans);
    t++;
  }
	return 0;
}


