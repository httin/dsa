#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
#define MAX 50
#define INF 1e9
int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};
int N, M;
string path = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<string> graph;
bool visited[MAX][MAX];
bool isValid(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}

int res;
void dfs(ii s, int len)
{
	res = max(res, len + 1);
	if (len + 1 == path.size())
		return;
	for (int i = 0; i < 8; i++) {
		int r = s.first + dr[i];
		int c = s.second + dc[i];
		if (isValid(r,c) && graph[r][c] == path[len + 1]) {
			dfs(ii(r,c), len + 1);
		}
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
			
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				visited[i][j] = false;
			}
		}
		
		graph.clear();
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			graph.push_back(s);
		}
		
		res = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (graph[i][j] == 'A')
					dfs(ii(i,j), 0);
			}
		}
		printf("Case %d: %d\n", t, res); 
		t++;
	}
	return 0;
}
