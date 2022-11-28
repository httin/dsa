#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    bool yes = false;
    string str, patt;
    cin >> str >> patt;
    unordered_set<char> s;
    for (char& c : patt) s.insert(c);
    
    for (char& c : str) {
      if (s.find(c) != s.end()) {
        cout << c << '\n';
        yes = true;
        break;
      }
    }
    
    if (yes) continue;
    cout << "No character present\n";
  }
  
  return 0;
}
