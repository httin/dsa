#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxN = 200;
array<int, maxN + 5> a;

int main() {
  int t,n;
  cin >> t;

  while (t-- > 0) {
    bool yes = false;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    
    for (int i=0; i<=30; i++)
    {
      unsigned int j = 1<<i;
      unsigned int ans=-1; // 2b111111..
      
      vector<int> test;
      for (int k=1; k<=n; k++) {
        if (a[k] & j) {
          //cout << "push " << a[k] << endl;
          test.push_back(a[k]);
        }
      }
      
      for (int num : test) ans &= num;
      
      if (ans == j) {
        yes = true;
        break;
      }
    }
    cout << (yes ? "YES" : "NO") << '\n';
  }
  
  return 0;
}
 
