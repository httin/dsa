#!/usr/bin/env python3
'''
From empty graph, add x[n], x[n-1],...,x[1]
For every x[i]:
	- Find the shortest path from x[i] to another vertices, vice versa -> O(n^2)
	- Update the shortest path between vertices with '' x[i] -> O(1)
'''
INF = 10**9
MAX = 505

n = int(input())
a = [[0 for i in range(n + 1)] for j in range(n + 1)]

for i in range(1, n + 1):
	l = list(map(int, input().split()))
	for j in range(n):
		a[i][j + 1] = l[j]

middleV = list(map(int, input().split()))
res = [0] * n
for i in range(n - 1, -1, -1):
	k = middleV[i]
	for u in range(1, n + 1):
		for v in range(1, n + 1):
			a[u][v] = min(a[u][v], a[u][k] + a[k][v])
	
	# print(k)
	for u in middleV[i:]:
		for v in middleV[i:]:
			res[i] += a[u][v]
			# print('a[{}][{}]={} -> {}'.format(u,v,a[u][v],res))
print(*res)
