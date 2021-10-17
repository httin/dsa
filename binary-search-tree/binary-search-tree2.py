#!/usr/bin/env python3

from queue import Queue

def bfs(s):
	visited = [False for _ in range(name_id)]
	q = Queue()
	
	dist[s] = 0
	q.put(s)
	visited[s] = True
	while not q.empty():
		u = q.get()
		for v in graph[u]:
			if not visited[v]:
				dist[v] = dist[u] + 1
				visited[v] = True
				q.put(v)

n = int(input())
d = {}
name_id = 0
graph = []
for i in range(n):
	index = []
	for name in input().split():
		if name not in d:
			d[name] = name_id
			index.append(name_id)
			name_id += 1
			graph.append([])
		else:
			index.append(d[name])
	
	for i in range(3):
		graph[index[i]].append(index[(i + 1)%3])
		graph[index[i]].append(index[(i + 2)%3])
	
dist = [-1 for _ in range(name_id)]
s = d['Isenbaev']
bfs(s)
for key in sorted(d.keys()):
	if dist[d[key]] != -1:
		print(key, dist[d[key]])
	else:
		print(key, 'undefined')
