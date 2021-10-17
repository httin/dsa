#!/usr/bin/env python3

from queue import Queue

V,E = map(int, input().split())
graph = [[] for _ in range(V)]
visited = [False]*V
path = [-1]*V
for i in range(E):
	u,v = map(int, input().split())
	graph[u].append(v)
	graph[v].append(u)

def bfs(start):
	global V, visited, graph, path
	
	q = Queue(V)
	q.put(start)
	visited[start] = True
	
	while not q.empty():
		u = q.get()
		for v in graph[u]:
			if not visited[v]:
				q.put(v)
				visited[v] = True
				path[v] = u

def recursivePath(src, dst):
	if src == dst:
		print(src, end=' ')
	else:
		if dst == -1:
			print('No path')
		else:
			recursivePath(src, path[dst])
			if path[dst] != -1:
				print(dst, end=' ')
	
bfs(0)
print(path)
recursivePath(0, 6)
