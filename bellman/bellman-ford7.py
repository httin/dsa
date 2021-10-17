#!/usr/bin/env python3

INF = (1 << 30) * 100 + 7
MAX = 105

def BellmanFord():
	for i in range(N):
		dist[i][i] = 0
		for j in range(N - 1):
			for u,v,w in graph:
				if dist[i][u] != INF:
					dist[i][v] = min(dist[i][v], w + dist[i][u])
		for j in range(N - 1):
			for u,v,w in graph:
				if dist[i][u] != INF and dist[i][v] > w + dist[i][u]:
					dist[i][v] = -INF

# Each test case: O(V^2 * E + Q) 
t = 1
while True:
	N = int(input())
	if N == 0:
		break
	city = {}
	graph = []
	dist = [[INF] * N for i in range(N)]
	
	for i in range(N):
		a = input().split()
		city[i] = a.pop(0)
		for j in range(N):
			w = int(a[j])
			if w == 0 and i != j:
				continue
			if w > 0 and i == j:
				w = 0
			graph.append((i, j, w))
	
	BellmanFord()
	
	print('Case #{}:'.format(t))
	Q = int(input())
	while Q > 0:
		Q -= 1
		u,v = map(int, input().split())
		if dist[u][v] == -INF:
			print('NEGATIVE CYCLE')
		elif dist[u][v] == INF:
			print('{}-{} NOT REACHABLE'.format(city[u], city[v]))
		else:
			print('{}-{} {}'.format(city[u], city[v], dist[u][v]))
	t += 1
						
