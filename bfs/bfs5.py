#!/usr/bin/env python3

from queue import Queue


def bfs():
	visited = [False for _ in range(N + 1)]
	q = Queue()
	
	q.put((1, M - a[0]))
	visited[1] = True

	res = 0
	while not q.empty():
		u,m = q.get()
		for v in graph[u]:
			if not visited[v]:
				# print('u={} v={} m={}'.format(u,v,m))
				if a[v - 1] == 0:
					if len(graph[v]) == 1:
						res += 1
						continue
					q.put((v, M))
					visited[v] = True
				elif m > 0:
					if len(graph[v]) == 1:
						res += 1
						continue
					q.put((v, m - 1))
					visited[v] = True
	return res

N, M = map(int, input().split())
a = list(map(int, input().split()))

graph = [[] for i in range(N + 1)]
for _ in range(N - 1):
	u,v = map(int, input().split())
	graph[u].append(v)
	graph[v].append(u)

print(bfs())
