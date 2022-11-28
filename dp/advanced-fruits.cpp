#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int scs(string& s1, string& s2, vector<vector<int>>& dp) {
  int m = s1.size();
  int n = s2.size();

  for(int i = 1; i <= m; ++i)
      dp[i][0] = i;
  for(int i = 0; i <= n; ++i)
      dp[0][i] = i;
  
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      dp[i][j] = (s1[i-1] == s2[j-1]) ? 
          dp[i-1][j-1] + 1 :
          1 + min(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[m][n];
}

string printSCS(string& s1, string& s2, vector<vector<int>>& dp) {
  int m = s1.size();
  int n = s2.size();
  string res("");
  int i = m;
  int j = n;

  while(i > 0 && j > 0) {
    if(s1[i-1] == s2[j-1]) {
      res.push_back(s1[i-1]);
      --i;
      --j;
    } else if (dp[i-1][j] > dp[i][j-1]) {
      res.push_back(s2[j-1]);
      --j;
    } else {
      res.push_back(s1[i-1]);
      --i;
    }
  }
  
  while(i > 0) {
    res.push_back(s1[i-1]);
    --i;
  }
  while(j > 0) {
    res.push_back(s2[j-1]);
    --j;
  }

  reverse(res.begin(), res.end());
  return res;
}

int main() {
  vector<string> ans;
  while (!cin.eof()) {
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    scs(s1, s2, dp);
    ans.push_back(printSCS(s1, s2, dp));
  }
  for (auto it = ans.begin(); it != ans.end(); it++) {
    cout << *it;
    if (it != ans.end()) cout << '\n';
  }
  return 0;
}
