#!/usr/bin/env python3

import queue

INF = 1e9 + 7

class Node:
	def __init__(self, id, dist):
		self.id = id
		self.dist = dist
	
	def __lt__(self, other):
		return self.dist <= other.dist

def dijkstra(s, f):
	dist = [INF for _ in range(n + 1)]
	pq = queue.PriorityQueue()
	pq.put(Node(s, 0))
	dist[s] = 0

	while not pq.empty():
		top = pq.get()
		u = top.id
		w = top.dist
		if u == f:
			break
		for v, cost in graph[u]:
			if cost + w < dist[v]:
				dist[v] = cost + w
				pq.put(Node(v, dist[v]))
	return dist[f]


T = int(input())
while T > 0:
	T -= 1
	
	n = int(input())
	graph = [[] for _ in range(n + 1)]
	city = []
	
	for u in range(1, n + 1):
		name = input()
		city.append(name)
		p = int(input())
		
		for _ in range(p):
			v, w = map(int, input().split())
			graph[u].append((v, w))
	
	r = int(input())
	for _ in range(r):
		name1, name2 = input().split()
		s = city.index(name1) + 1
		f = city.index(name2) + 1
		
		print(dijkstra(s, f))
	input()
