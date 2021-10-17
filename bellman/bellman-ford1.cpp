#include <bits/stdc++.h>

using namespace std;
#define MAX 1005
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
int n,m;

bool BellmanFord(int s)
{
	dist[s] = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (auto& edge : graph) {
			int u = edge.u;
			int v = edge.v;
			int w = edge.w;
			if (dist[u] != INF && dist[v] > w + dist[u]) {
				dist[v] = w + dist[u];
			}
		}
	}
	for (auto& e : graph) {
		if (dist[e.u] != INF && dist[e.v] > e.w + dist[e.u])
			return false;
	}
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T-- > 0)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			dist[i] = INF;
		graph.clear();
		for (int i = 0; i < m; ++i)
		{
			int u,v,w;
			scanf("%d%d%d", &u, &v, &w);
			graph.push_back(Edge(u,v,w));
		}
		printf("%s\n", (BellmanFord(0) ? "not possible" : "possible"));
	}
	return 0;
}
