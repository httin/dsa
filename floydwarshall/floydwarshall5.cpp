#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
#define MAX 85
#define INF 1e9
int dist[MAX][MAX];
int maxCost[MAX][MAX]; // maxCost(i,j)
int cost[MAX];
int C,R,Q;

void FloydWarshall()
{
	int times = 2;
	while (times--)
	{
	for (int k = 1; k <= C; k++)
		for (int u = 1; u <= C; u++)
			for (int v = 1; v <= C; v++) 
			{
				int max_cost = max(maxCost[u][k], maxCost[k][v]);
				if (dist[u][k] != INF && dist[k][v] != INF && 
					dist[u][v] + maxCost[u][v] > dist[u][k] + dist[k][v] + max_cost)
				{
					dist[u][v] = dist[u][k] + dist[k][v];
					maxCost[u][v] = max_cost;
				}
			}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t = 0, c1, c2, d, a, b;
	while (++t)
	{
		cin >> C >> R >> Q;
		if (C == 0 && R == 0 && Q == 0)
			break;
		for (int i = 1; i <= C; ++i)
			cin >> cost[i];

		for (int i = 1; i <= C; ++i)
			for (int j = 1; j <= C; ++j) {
				dist[i][j] = (i == j) ? 0 : INF;
				maxCost[i][j] = max(cost[i], cost[j]);
			}
		
		for (int i = 1; i <= R; i++) {
			cin >> c1 >> c2 >> d;
			dist[c1][c2] = dist[c2][c1] = d;
		}
		
		FloydWarshall();
		
		if (t > 1)
			cout << '\n';
		cout << "Case #"  << t << '\n';
		for (int i = 0; i < Q; ++i) {
			cin >> a >> b;
			if (dist[a][b] == INF)
				cout << "-1\n";
			else
				cout << dist[a][b] + maxCost[a][b] << '\n';
		}
	}
	return 0;
}

