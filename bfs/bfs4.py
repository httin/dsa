#!/usr/bin/env python3

from queue import Queue

dr = [0,0,1,-1]
dc = [1,-1,0,0]

def isValid(r,c):
	return r >= 0 and r < H and c >=0 and c < W

def BFS(s):
	q = Queue()
	visited = [[False for i in range(W)] for j in range(H)]
	
	q.put(s)
	visited[s[0]][s[1]] = True
	res = 1
	while not q.empty():
		node = q.get()
		for i in range(4):
			r = node[0] + dr[i]
			c = node[1] + dc[i]
			if isValid(r,c) and graph[r][c] == '.' and not visited[r][c]:
				res += 1
				q.put((r,c))
				visited[r][c] = True
	return res

T = int(input())
for t in range(1, T + 1):
	W,H = map(int, input().split())
	graph = []
	
	s = None
	for r in range(H):
		graph.append(input())
		for c in range(W):
			if graph[r][c] == '@':
				s = (r,c)
	
	print('Case {}: {}'.format(t, BFS(s)))
	
