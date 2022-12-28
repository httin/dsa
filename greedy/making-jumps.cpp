#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

const int maxN = 2e5;
const int dr[8] = {-2,-2,-1,-1,+1,+1,+2,+2};
const int dc[8] = {-1,+1,-2,+2,-2,+2,-1,+1};

bool isValid(int r, int c, vector<vector<char>>& chess) {
  return r >= 0 && r < 10 && c >= 0 && c < 10 && chess[r][c] == '.';
}

void dfs(int r, int c, int& cnt, int& maxcnt, vector<vector<bool>>& visit, vector<vector<char>>& chess) {
  visit[r][c] = true;
  ++cnt;
  maxcnt = max(maxcnt, cnt);
  for (int i=0; i<8; i++) {
    int u = r + dr[i];
    int v = c + dc[i];
    if (isValid(u, v, chess) && !visit[u][v]) {
      dfs(u, v, cnt, maxcnt, visit, chess);
    }
  }
  --cnt;
  visit[r][c] = false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int cs = 0;
  while (true) {
    int n, squares = 0, cnt = 0, maxcnt = 0;
    cin >> n;
    if (n == 0) break;

    vector<vector<bool>> visit(10, vector<bool>(10, false));
    vector<vector<char>> chess(10, vector<char>(10, 'x')); // prohibited

    int sr=0, sc;
    for (int i=0; i<n; i++) {
      int start, num;
      cin >> start >> num;
      if (i == 0) {
        sc = start;
      }
      squares += num;
      for (int j = start; j < start + num; j++) {
        chess[i][j] = '.'; // available
      }
    }

    dfs(sr, sc, cnt, maxcnt, visit, chess);
    //cout << sr << ' ' << sc << ' ' << cnt << ' ' << maxcnt << ' ' << squares << endl;
    ++cs;
    if (squares - maxcnt == 1)
      cout << "Case " << cs << ", " << squares - maxcnt << " square can not be reached.\n";
    else
      cout << "Case " << cs << ", " << squares - maxcnt << " squares can not be reached.\n";
  }
  return 0;
}
