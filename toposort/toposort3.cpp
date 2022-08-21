#include <bits/stdc++.h>

using namespace std;

const int maxN = 26;
vector<int> graph[maxN];
array<int, maxN> indeg;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; // [1,100]
  cin >> n;
  vector<string> names(n);
  for (int i=0; i<n; i++) cin >> names[i]; // All names are different.

  bool greater[maxN][maxN];
  memset(greater, 0, maxN * maxN);
  for (int i=0; i<n-1; i++) {
    bool suffix = true;
    string s1 = names[i];
    string s2 = names[i+1];
    int l = (int)min(s1.length(), s2.length());

    for (int j=0; j<l; j++) {
      int x = s1[j] - 'a';
      int y = s2[j] - 'a';
      if (x != y) {
        greater[x][y] = true;
        suffix = false;
        break;
      }
    }
    
    if (suffix && s1.length() > s2.length()) {
      cout << "Impossible\n";
      exit(0);
    }
  }
  
  for (int i=0; i<maxN; i++) {
    for (int j=0; j<maxN; j++) {
      if (greater[i][j])
        graph[i].push_back(j);
    }
  }
  
  for (int u=0; u<maxN; u++)
    for (int v : graph[u])
      indeg[v]++;
  
  queue<int> zero;
  vector<int> res;
  
  for (int u=0; u<maxN; u++)
    if (indeg[u] == 0) zero.push(u);

  while (!zero.empty()) {
    int u = zero.front();
    zero.pop();
    res.push_back(u);
    
    for (int v : graph[u]) {
      indeg[v]--;
      if (indeg[v] == 0)
        zero.push(v);
    }
  }
  
  for (int u=0; u<maxN; u++) {
    if (indeg[u] != 0) {
      cout << "Impossible\n";
      return 0;
    }
  }
  
  for (int c : res) cout << (char)(c + 'a');
  cout << endl;
  
  return 0;
}
