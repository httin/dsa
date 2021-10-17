#!/usr/bin/env python3

import queue

MAX = 101
INF = int(1e9) + 1

class Node:
	def __init__(self, id, dist):
		self.id = id
		self.dist = dist
	
	def __lt__(self, other):
		return self.dist <= other.dist

def dijkstra(s):
	global graph, dist, path
	pq = queue.PriorityQueue()
	pq.put(Node(s, 0))
	dist[s] = 0
	while not pq.empty():
		top = pq.get()
		u = top.id
		w = top.dist
		if dist[u] != w:
			continue
		for v, cost in graph[u]:
			if cost + w < dist[v]:
				dist[v] = cost + w
				path[v] = u
				pq.put(Node(v, cost + w))

N = int(input())
E = int(input())
T = int(input())
M = int(input())

graph = [[] for _ in range(N + 1)]
dist = [INF for _ in range(N + 1)]
path = [-1 for _ in range(N + 1)]

for _ in range(M):
	u,v,w = map(int, input().split())
	graph[v].append((u,w))

dijkstra(E)

ret = 0
for w in dist:
	if w <= T:
		ret += 1

print(ret)
