#!/usr/bin/env python3

MAX = 49 # [0,48]

def floydwarshall(dist):
	for k in range(V):
		for u in range(V):
			for v in range(V):
				if u < k and k < v and dist[u][v] < dist[u][k] + dist[k][v]:
					dist[u][v] = dist[u][k] + dist[k][v]

T = int(input())
while T > 0:
	T -= 1
	V = int(input())
	dist = [[0 for i in range(V + 1)] for j in range(V + 1)]
	
	for i in range(V):
		s,e,c = map(int, input().split())
		dist[s][e] = max(dist[s][e], c)
	
	print(dist)
	floydwarshall(dist)
	print(dist)
