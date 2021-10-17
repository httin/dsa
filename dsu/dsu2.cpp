#include <bits/stdc++.h>

using namespace std;
#define MAX 26 + 5

int parent[MAX];
int ranks[MAX];
int N;

void makeSet()
{
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
		ranks[i] = 0;
	}
}

int findSet(int u)
{
	if (parent[u] != u)
		parent[u] = findSet(parent[u]);
	return parent[u];
}

void unionSet(int u, int v)
{
	int pu = findSet(u);
	int pv = findSet(v);
	if (pu == pv)
		return;
	if (ranks[pu] > ranks[pv]) {
		parent[pv] = pu;
	}
	else if (ranks[pu] < ranks[pv]) {
		parent[pu] = pv;
	}
	else {
		parent[pu] = pv;
		ranks[pv]++;
	}
	N--;
}

int main()
{
	int T;
	cin >> T;
	string _;
	std::getline(cin, _);
	std::getline(cin, _);
	while (T > 0)
	{
		string s;
		unordered_set<int> set;
		std::getline(cin, s);
		N = s[0] - 'A' + 1;
		makeSet();
		while (std::getline(cin, s) && !s.empty())
		{
			int u,v;
			u = s[0] - 'A';
			v = s[1] - 'A';
			set.insert(u);
			set.insert(v);
			//cout << u << ' ' << v << ' ' << set.size() << endl;
			unionSet(u, v);
		}
		
		cout << N << '\n' << endl;
		--T;
	}
	
	return 0;
}
