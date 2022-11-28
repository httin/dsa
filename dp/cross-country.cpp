#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> split(string target, string delimiter)
{
    vector<int> res;
    if (!target.empty())
    {
         size_t start = 0;
         do
         {
             const size_t index = target.find(delimiter, start);
             if (index == string::npos)
                 break;
             const size_t length = index - start;
             res.push_back(stoi(target.substr(start, length)));
             start += (length + delimiter.size());
         } while (true);
         res.push_back(stoi(target.substr(start)));
    }

    return res;
}

vector<int> input() {
  string s;
  getline(cin, s);
  vector<int> res = split(s, " ");
  res.pop_back();
  return res;
}


int lcs(vector<int>& agness, vector<int>& card) {
  int m = agness.size();
  int n = card.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  
  for (int i=1; i<=m; i++) {
    for (int j=1; j<=n; j++) {
      if (agness[i - 1] == card[j - 1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  
  return dp[m][n];
}

int main() {
  int t;
  cin >> t;
  cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 

  while (t--) {
    vector<int> agness = input();
    int res = 0;
    while (true) {
      vector<int> card = input();
      if (card.empty()) break;
      res = max(res, lcs(agness, card));
    }
    cout << res << '\n';
  }
  
  return 0;
}
