#include <bits/stdc++.h>

using namespace std;
#define INF 1e9
#define MAX 1005
struct Edge {
	int u;
	int v;
	int w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
vector<Edge> graph;
int dist[MAX];
int n,m,q,s;

void BellmanFord(int S)
{
	dist[S] = 0;
	for (int i = 1; i <= n - 1; ++i) {
		for (auto& e : graph) {
			if (dist[e.u] != INF && dist[e.v] > e.w + dist[e.u])
				dist[e.v] = e.w + dist[e.u];
		}
	}
	for (int i = 1; i <= n - 1; ++i) {
		for (auto& e : graph) {
			if (dist[e.u] != INF && dist[e.v] > e.w + dist[e.u])
				dist[e.v] -= INF;
		}
	}
}

int main()
{
	while (true)
	{
		scanf("%d%d%d%d", &n, &m, &q, &s);
		if (n == 0 && m == 0 && q == 0 && s == 0)
			break;
		graph.clear();
		for (int i = 0; i < n; i++)
			dist[i] = INF;

		int a,b,w;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d",&a,&b,&w);
			graph.push_back(Edge(a,b,w));
		}
		
		BellmanFord(s);
		
		int x;
		for (int i = 0; i < q; ++i) {
			scanf("%d", &x);
			if (dist[x] == INF)
				printf("Impossible\n");
			else if (dist[x] < -1e7)
				printf("-Infinity\n");
			else
				printf("%d\n", dist[x]);
		}
		puts("");
	}
	
	return 0;
}

