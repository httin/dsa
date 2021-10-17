#!/usr/bin/env python3

import queue

def dfs(s):
	dist = [-1] * (V + 1) # shortest path from s to i
	longest_dist = None
	leaf = None
	
	# start
	stack = [s]
	dist[s] = 0
	while len(stack):
		u = stack.pop()
		for v, w in graph[u]:
			if dist[v] == -1:
				# print("{}->{}: {}, total={}".format(u,v,w,longest_dist))
				stack.append(v)
				dist[v] = dist[u] + w
				if longest_dist == None or dist[v] > longest_dist:
					longest_dist = dist[v]
					leaf = v
	return leaf, longest_dist

T = int(input())
while T > 0:
	T -= 1
	V = int(input())
	graph = [[] for _ in range(V + 1)]
	for i in range(V - 1):
		u,v,w = map(int, input().split())
		graph[u].append((v,w))
		graph[v].append((u,w))

	leaf1, _ = dfs(1)
	leaf2, distance = dfs(leaf1)
	print(distance)
