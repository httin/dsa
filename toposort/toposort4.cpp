#include <bits/stdc++.h>

using namespace std;

using pii = pair<int,int>;
using ll = long long;

const ll lim = 1e9;
const int maxN = 100005;
const int dr[8] = {-1,-1,-1,0,0,1,1,1};
const int dc[8] = {-1,0,1,-1,1,-1,0,1};
map<ll, int> dist;
set<ll> mark;

inline bool isValid(ll x, ll y) {
  return x >= 0 && x < lim && y >= 0 && y < lim;
}

inline ll K(ll x, ll y) {
  return x*1000000000LL + y;
}

int main() {
  ll x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1; // [1,1e9]
  x0--; y0--; x1--; y1--;
  ll start = K(x0, y0);
  ll end = K(x1, y1);
  
  int n;
  cin >> n; // [1,1e5]
  
  for (int i=1; i<=n; i++) {
    int r,a,b;
    cin >> r >> a >> b;
    r--; a--; b--;
    for (int c=a; c<=b; c++) {
      mark.insert(K(r, c));
    }
  }
  
  mark.insert(start);
  queue<ll> q;
  q.push(start);
  dist[start] = 0;
  
  while(!q.empty()) {
    ll u = q.front();
    q.pop();
    ll x = u / lim;
    ll y = u % lim;
    for (int i=0; i<8; i++) {
      ll xx = x + dr[i];
      ll yy = y + dc[i];
      ll v = K(xx, yy);
      if (isValid(xx, yy) && (mark.find(v) != mark.end())) {
        if (dist.find(v) == dist.end()) {
          dist[v] = dist[u] + 1;
          
          if (v == end) {
            cout << dist[v];
            return 0;
          }
          
          q.push(v);
        }
      }
    }
  }
  
  cout << -1;
  return 0;
}
