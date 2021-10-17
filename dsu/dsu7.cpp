/*
 * Dữ liệu nhập
 * The first line consists of two space separated integers, N and Q.
 * The next Q line consists of two integers, A and B, meaning that
 * the groups involving survivor A and survivor B unite into a larger
 * group.
 * 
 * Dữ liệu xuất
 * Output Q lines, the answer after each query.
 * 1 ≤ N ≤ 100000, 1 ≤ Q ≤ 100000
 */
#include <bits/stdc++.h>

using namespace std;
#define MAX 100005

int parent[MAX];
int cnt[MAX];
int top1 = 1;
int n,q;
using ii = pair<int, int>;
std::priority_queue<ii, vector<ii>, greater<ii>> pq;

void makeSet()
{
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		cnt[i] = 1;
		pq.push(ii(1, i));
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
	if (pu == pv) // connected
		return;
	if (cnt[pu] > cnt[pv]) {
		parent[pv] = pu;
		cnt[pu] += cnt[pv];
		top1 = max(top1, cnt[pu]);
		pq.push(ii(cnt[pu], pu));
	}
	else {
		parent[pu] = pv;
		cnt[pv] += cnt[pu];
		top1 = max(top1, cnt[pv]);
		pq.push(ii(cnt[pv], pv));
	}
}

void print() {
	cout << "Rank: ";
	for (int i = 0; i < MAX; ++i) {
		cout << cnt[i] << ' ';
	}
	cout << "\nParent: ";
	for (int i = 0; i < MAX; ++i) {
		cout << parent[i] << ' ';
	}
	cout << endl;
}

int main()
{
	scanf("%d %d", &n, &q);
	makeSet();
	for (int i = 0; i < q; ++i)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		union_set(a - 1, b - 1);
		while (true) {
			ii tmp = pq.top();
			int u = findSet(tmp.second);
			if (u != tmp.second) {
				// tmp.second is in another group
				pq.pop();
				continue;
			}
			
			if (cnt[u] != tmp.first) {
				pq.pop();
				continue;
			}
			
			break;
		}
		printf("%d\n", top1 - pq.top().first);
	}
	return 0;
}
