#!/usr/bin/env python3

INF = 1e9
MAX = 105

def BellmanFord(s):
	dist[s] = 0
	for i in range(N - 1):
		for u,v,w in graph:
			if dist[u] != -INF:
				dist[v] = max(dist[v], w + dist[u])
	for u,v,w in graph:
		if dist[v] != -INF and dist[v] < w + dist[u]:
			return False
	return True

T = int(input())
while T > 0:
	T -= 1
	N,M = map(int, input().split())
	graph = []
	dist = [-INF] * (N + 1)
	for i in range(M):
		u,v,w = map(int, input().split())
		graph.append((u,v,w))
	
	print('No' if BellmanFord(1) else 'Yes')
