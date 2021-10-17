#include <bits/stdc++.h>

using namespace std;
#define MAX 200005

int main()
{
	int n,b;
	long long res[MAX];
	long long t,d;
	long long now = 0;
	queue<int> q;

	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; ++i)
		res[i] = -1;

	for (int i = 0; i < n; ++i)
	{
		scanf("%lld %lld", &t, &d);
		
		while (!q.empty() && t >= q.front())
		{
			q.pop();
		}
		
		if (q.size() <= b) {
			now = max(now, t) + d;
			res[i] = now;
			q.push(now);
		}
	}
	
	for (int i = 0; i < n; ++i)
		printf("%lld ", res[i]);

	return 0;
}
