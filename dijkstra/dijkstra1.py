#!/usr/bin/env python3

import queue

MAX = 501
INF = int(1e9)

class Node:
	def __init__(self, id, dist):
		self.id = id
		self.dist = dist
	
	def __lt__(self, other):
		return self.dist <= other.dist

N = int(input())
graph = [[] for _ in range(MAX + 5)]
dist = [INF for _ in range(MAX + 5)]
path = [-1 for _ in range(MAX + 5)]

def dijkstra(s):
	global graph, dist, path
	pq = queue.PriorityQueue()
	pq.put(Node(s, 0))
	dist[s] = 0
	while not pq.empty():
		top = pq.get()
		u = top.id
		w = top.dist
		# TODO: optimize
		for v, cost in graph[u]:
			if cost + w < dist[v]:
				dist[v] = cost + w
				path[v] = u
				pq.put(Node(v, cost + w))
	

for _ in range(N):
	u,v,w = map(int, input().split())
	graph[u].append((v,w))
	graph[v].append((u,w))

S = int(input())
dijkstra(S)

Q = int(input())
while Q > 0:
	Q -= 1
	q = int(input())
	print('-------{} '.format(q), end=' ')
	if dist[q] != INF:
		print(dist[q])
	else:
		print('No path')
