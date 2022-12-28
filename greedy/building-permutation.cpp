#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

const int maxN = 3e5;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    ll res=0;
    for (int i=1; i<=n; i++) res += abs(i - a[i-1]) + 0LL;
    cout << res << endl;

    return 0;
}
