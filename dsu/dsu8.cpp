#include <bits/stdc++.h>

using namespace std;
#define MAX 100005

int p[MAX];
int parent[MAX];
int ranks[MAX];
int n,a,b;

void makeSet()
{
	for (int i = 0; i <= n + 1; ++i) {
		parent[i] = i;
		ranks[i] = 1;
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
	int pu = findSet(u);
	int pv = findSet(v);
	if(pu != pv)
	{
		if (ranks[pu] >= ranks[pv])
		{
			parent[pv] = pu;
			ranks[pu] += ranks[pv];
		}
		else
		{
			parent[pu] = pv;
			ranks[pv] += ranks[pu];
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	map<int, int> mp;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		mp[p[i]] = i;
	}
	
	makeSet();
	for (int i = 1; i <= n; ++i) {
		if (mp[a - p[i]])
			union_set(i, mp[a - p[i]]);
		else
			union_set(i, 0); // p[i] isn't in A, maybe in B
		
		if (mp[b - p[i]])
			union_set(i, mp[b - p[i]]);
		else
			union_set(i, n + 1); // p[i] isn't in B, maybe in A
		//printf("p[%d]=%d mp[%d]=%d mp[%d]=%d\n", i, p[i], a - p[i],
			//mp[a - p[i]], b - p[i], mp[b - p[i]]);
	}
	
	int A = findSet(n + 1);
	int B = findSet(0);
	if (A == B) {
		// there is one p[i] not in A nor B
		printf("NO\n");
	} else {
		printf("YES\n");
		for (int i = 1; i <= n; ++i) {
			if (i != 1)
				printf(" ");
			if (findSet(i) == A) {
				printf("0");
			}
			else {
				printf("1");
			}
		}
		printf("\n");
	}
	
	return 0;
}
