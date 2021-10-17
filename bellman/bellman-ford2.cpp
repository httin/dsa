#include <bits/stdc++.h>

using namespace std;
#define MAX 205
#define INF 1e9

struct Edge
{
	int u;
	int v;
	int w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
vector<Edge> graph;
int dist[MAX];
int n,m,q;

void BellmanFord(int s)
{
	dist[s] = 0;
	for (int i = 1; i <= n - 1; ++i) {
		for (auto& e : graph) {
			if (dist[e.u] != INF && dist[e.v] > e.w + dist[e.u]) {
				dist[e.v] = e.w + dist[e.u];
			}
		}
	}
	for (int i = 1; i <= n - 1; ++i) {
		for (auto& e : graph) {
			if (dist[e.u] != INF && dist[e.v] > e.w + dist[e.u]) {
				dist[e.v] -= INF;
			}
		}
	}
}

inline int f(int x) {
	return x*x*x;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d", &n);
		vector<int> a(n + 1);
		graph.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			dist[i] = INF;
		}
		scanf("%d", &m);
		int u,v,target,ans;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			graph.push_back(Edge(u,v,f(a[v] - a[u])));
		}
		
		BellmanFord(1);
		
		scanf("%d", &q);
		printf("Case %d:\n", t);
		for (int i = 0; i < q; ++i) {
			scanf("%d",&target);
			ans = dist[target];
			if (ans >= 3 && ans != INF)
				printf("%d\n", ans);
			else
				printf("?\n");
		}
	}
	return 0;
}

