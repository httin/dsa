#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
#define MAX 105

int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};

int N, M;
std::string graph[MAX];
std::string path = "ALLIZZWELL";
bool visited[MAX][MAX];

bool isValid(int r, int c) {
  return (r >= 0 && r < N && c >= 0 && c < M);
}

bool found;
void dfs(ii s, int level)
{
  if (level == path.size() - 1) {
    found = true;
    return;
  }
  // printf("(%d,%d) -> level=%d - %c\n", s.first, s.second, level, graph[s.first][s.second]);
  for (int i = 0; i < 8; ++i) {
    int r = s.first + dr[i];
    int c = s.second + dc[i];
    if (isValid(r,c) && !visited[r][c] && graph[r][c] == path[level + 1]) {
      visited[s.first][s.second] = true;
      dfs(ii(r,c), level + 1);
      visited[s.first][s.second] = false;
    }
  }
}


int main() 
{
  int T;
  cin >> T;
  
next:
  while (T-- > 0)
  {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
      cin >> graph[i];
    found = false;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        visited[i][j] = false;
    
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        if (!visited[i][j] && graph[i][j] == 'A') {
          dfs(ii(i,j), 0);
          if (found) {
            cout << "YES\n";
            goto next;
          }
        }
    cout << "NO\n";
  }
	return 0;
}
