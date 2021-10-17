#include <bits/stdc++.h>

using namespace std;
#define MAX 10000

int friends[MAX * 2];
int ranks[MAX * 2];
int N;

void makeSet()
{
	for (int i = 0; i < 2 * N; ++i)
	{
		friends[i] = i;
		ranks[i] = 0;
	}
}

int findSet(int u)
{
	if (u != friends[u])
		friends[u] = findSet(friends[u]);
	return friends[u];
}

bool areFriends(int u, int v)
{
	return findSet(u) == findSet(v);
}

bool areEnemies(int u, int v)
{
	return findSet(u) == findSet(v + N);
}

void union_set(int u, int v)
{
	int pu = findSet(u);
	int pv = findSet(v);
	if (pu == pv)
		return;
	if (ranks[pu] > ranks[pv])
		friends[pv] = pu;
	else if (ranks[pu] < ranks[pv])
		friends[pu] = pv;
	else
	{
		friends[pu] = pv;
		ranks[pv]++;
	}
}

void print() {
	cout << '[';
	for (int i = 0; i < 2*N; ++i) {
		cout << friends[i] << ' ';
	}
	cout << "]\n";
}

int main()
{
	cin >> N;
	makeSet();
	while (true)
	{
		int c,x,y;
		cin >> c >> x >> y;
		if (c == 0 && x == 0 && y == 0)
			break;
		
		switch (c)
		{
			case 1: // add friends
				if (areEnemies(x, y)) {
					cout << -1 << '\n';
					break;
				}
				union_set(x, y);
				union_set(x + N, y + N);
				break;
			case 2: // add enemies
				if (areFriends(x, y)) {
					cout << -1 << '\n';
					break;
				}
				union_set(x, y + N);
				union_set(x + N, y);
				break;
			case 3: // is friend
				cout << (areFriends(x ,y) ? 1 : 0) << '\n';
				break;
			case 4: // is enemy
				cout << (areEnemies(x, y) ? 1 : 0) << '\n';
				break;
		}
	}
	return 0;
}
