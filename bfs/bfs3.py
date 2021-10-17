#!/usr/bin/env python3

from queue import Queue

MAX = 100000 + 5

def BFS(s, f):
	q = Queue()
	
	q.put(s)
	dist[s] = 0
	while not q.empty():
		u = q.get()
		for v in a:
			k = (u * v) % 100000
			if dist[k] == -1:
				dist[k] = dist[u] + 1
				q.put(k)
			
			if k == f:
				return dist[k]
			
	return -1

s, f = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))

# graph = [[] for _ in range(MAX)]
dist = [-1 for _ in range(MAX)]

print(BFS(s, f))
