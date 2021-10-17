#include <bits/stdc++.h>

using namespace std;
#define MAX 100

int parent[MAX];
int ranks[MAX];
int n,m;

void makeSet()
{
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		ranks[i] = 0;
	}
}

int findSet(int u)
{
	if (u != parent[u])
		parent[u] = findSet(parent[u]);
	return parent[u];
}

void union_set(int u, int v)
{
	int pu = findSet(v);
	int pv = findSet(u);
	if (pu == pv) // connected
		return;
	if (ranks[pu] > ranks[pv])
		parent[pv] = pu;
	else if (ranks[pu] < ranks[pv])
		parent[pu] = pv;
	else {
		parent[pu] = pv;
		ranks[pv]++;
	}
	n--;
}

int main()
{
	cin >> n >> m;
	if (n != m) {
		cout << "NO" << endl;
		return 0;
	}
	
	makeSet();
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		union_set(x - 1, y - 1);
	}
	
	if (n == 1)
		cout << "FHTAGN!";
	else
		cout << "NO";
	
	return 0;
}
