#include <bits/stdc++.h>

using namespace std;
#define MAX 105
#define INF 1e9

struct Edge {
	int u;
	int v;
	int w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
vector<Edge> graph;
int dist[MAX];
int N;

int BellmanFord(int s) {
	dist[s] = 0;
	for (int i = 1; i <= N - 1; i++) {
		for (auto& e : graph) {
			if (dist[e.u] != INF) {
				dist[e.v] = min(dist[e.v], e.w + dist[e.u]);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= N; ++i) {
		res = max(res, dist[i]);
	}
	return res;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i <= N; i++)
		dist[i] = INF;
	string s;
	for (int u = 2; u <= N; u++)
		for (int v = 1; v < u; v++) {
			cin >> s;
			if (s != "x") {
				int w = atoi(s.c_str());
				graph.push_back(Edge(u,v,w));
				graph.push_back(Edge(v,u,w));
			} 
		}
	
	cout << BellmanFord(1) << endl;
	return 0;
}
