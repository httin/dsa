#!/usr/bin/env python3

INF = 1000000000

def FloydWarshall(dist, V):
	for k in range(V):
		for i in range(V):
			for j in range(V):
				if dist[i][k] != INF and dist[k][j] != INF and \
				dist[i][j] > dist[i][k] + dist[k][j]:
					dist[i][j] = dist[i][k] + dist[k][j]
	return True

T = int(input())
while T > 0:
	T -= 1
	a = []
	a.append(input())
	V = len(a[0])
	for _ in range(V-1):
		a.append(input())
	dist = [[0 for i in range(V)] for j in range(V)]
	
	for i in range(V):
		for j in range(V):
			if i != j:
				if a[i][j] == 'Y':
					dist[i][j] = 1
				else:
					dist[i][j] = INF
	
	FloydWarshall(dist, V)
	
	cnt = [0]*V;
	for u in range(V):
		for v in range(V):
			if dist[u][v] == 2:
				cnt[u] += 1
				cnt[v] += 1
	
	ans = 0
	for i in range(0, V):
		if cnt[i] > cnt[ans]:
			ans = i
	print(ans, cnt[ans]//2)
