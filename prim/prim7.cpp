#include <bits/stdc++.h>

using namespace std;

#define INF 1000000 + 5 
using Node = pair<int, int>;
struct comp {
	bool operator () (const Node& a, const Node& b) {
		return a.second > b.second;
	}
};

vector<vector<Node>> graph;
void mst(vector<int>& dist, vector<bool>& visited)
{
	std::priority_queue<Node, vector<Node>, comp> pq;
	pq.push(Node(0, 0));
	dist[0] = 0;
	
	while (!pq.empty()) {
		Node top = pq.top();
		pq.pop();
		int u = top.first;
		visited[u] = true;
		for (size_t i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] && dist[v] > w) {
				dist[v] = w;
				pq.push(Node(v,w));
			}
		}
	}
}

int main()
{
	int N, M, Q;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		graph.push_back(vector<Node>());
	vector<bool> visited(N, false);
	vector<int> dist(N, INF);
	for (int i = 0; i < M; ++i) {
		int a,b,l;
		cin >> a >> b >> l;
		graph[a - 1].push_back(Node(b - 1, l));
		graph[b - 1].push_back(Node(a - 1, l));
	}
	cin >> Q;
	vector<int> q(Q);
	for (int i = 0; i < Q; ++i) {
		int c;
		cin >> c;
		q[i] = c;
	}
	
	mst(dist, visited);
	std::sort(q.begin(), q.end());
	std::sort(dist.begin(), dist.end(), 
		[](int i, int j) -> bool { return i > j; });
	
	int i = 0;
	while (dist[i] > q[i] && i < min(N,Q)) {
		dist[i] = q[i];
		++i;
	}
	long long sum = std::accumulate(dist.begin(), dist.end(), 
		decltype(dist)::value_type(0));
	cout << sum << endl;
	
	return 0;
}
