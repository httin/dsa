#!/usr/bin/env python3

from queue import Queue

dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]

class Point:
	def __init__(self, r, c):
		self.r = r
		self.c = c

def isValid(r, c):
	global m,n
	return r >= 0 and r < m and c >= 0 and c < n

def BFS(s, f):
	global m,n,graph
	visited = [[False for i in range(n)] for j in range(m)]
	# path = [[None for i in range(n)] for j in range(m)]
	q = Queue()
	
	q.put(s)
	visited[s.r][s.c] = True
	graph[s.r][s.c] = 1
	while not q.empty():
		node = q.get()
		if node.r == f.r and node.c == f.c:
			break
		for i in range(4):
			r = node.r + dr[i]
			c = node.c + dc[i]
			if isValid(r, c) and not visited[r][c] and graph[r][c] != -1:
				q.put(Point(r, c))
				visited[r][c] = True
				graph[r][c] = graph[node.r][node.c] + 1
	return graph[f.r][f.c] - 1

while True:
	global m,n,graph
	m,n = map(int, input().split())
	if m == 0 and n == 0:
		break
	graph = [[0 for i in range(n)] for j in range(m)]
	for _ in range(int(input())):
		l = list(map(int, input().split()))
		r = l[0]
		for i in range(l[1]):
			c = l[i + 2]
			graph[r][c] = -1
	
	Sr, Sc = map(int, input().split())
	Dr, Dc = map(int, input().split())
	
	print(BFS(Point(Sr, Sc), Point(Dr, Dc)))
	
