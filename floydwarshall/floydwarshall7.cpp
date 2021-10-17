#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
#define MAX 49
#define INF 1e9
int dist[MAX][MAX];
int N;

int FloydWarshall()
{
	for (int k = 0; k < MAX; k++)
		for (int u = 0; u < MAX; u++)
			for (int v = u + 1; v < MAX; v++)
				if (u <= k && k <= v && dist[u][v] < dist[u][k] + dist[k][v])
					dist[u][v] = dist[u][k] + dist[k][v];
	return dist[0][48];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				dist[i][j] = (j > i) ? 0 : -INF;
		
		for (int i = 0; i < N; i++) {
			int s,e,c;
			cin >> s >> e >> c;
			if (c > dist[s][e]
				dist[s][e] = c;
		}
		
		cout << FloydWarshall() << '\n';
	}
	return 0;
}
