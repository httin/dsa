#include <bits/stdc++.h>

using namespace std;
#define MAX 30000 + 5

int parent[MAX];
int ranks[MAX];
int dist[MAX];
int res;

void makeSet(int N)
{
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
		ranks[i] = 0;
		dist[i] = 1;
	}
	res = 1;
}

int findSet(int u)
{
	if (parent[u] != u)
		parent[u] = findSet(parent[u]);
	return parent[u];
}

void unionSet(int u, int v)
{
	int pu = findSet(u);
	int pv = findSet(v);
	if (pu == pv)
		return;
	res = max(res, dist[pu] + dist[pv]);
	if (ranks[pu] > ranks[pv]) {
		parent[pv] = pu;
		dist[pu] += dist[pv];
	}
	else if (ranks[pu] < ranks[pv]) {
		parent[pu] = pv;
		dist[pv] += dist[pu];
	}
	else {
		parent[pu] = pv;
		dist[pv] += dist[pu];
		ranks[pv]++;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		int N, M;
		cin >> N >> M;
		makeSet(N);
		for (int i = 0; i < M; ++i) {
			int u,v;
			cin >> u >> v;
			unionSet(u-1, v-1);
		}
		cout << res << '\n';
		T--;
	}
	return 0;
}
