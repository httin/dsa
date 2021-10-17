#!/usr/bin/env python3

from queue import Queue

class Node:
	def __init__(self, r, c):
		self.r = r
		self.c = c
	
	def isValid(self):
		return self.r >= 0 and self.r < R and self.c >= 0 and self.c < C

dr = [0,0,1,-1]
dc = [1,-1,0,0]

def BFS(s, f):
	q = Queue()
	visited = [[False for i in range(C)] for j in range(R)]
	
	q.put(s)
	visited[s.r][s.c] = True
	while not q.empty():
		node = q.get()
		if node.r == f.r and node.c == f.c:
			return True
		for _ in range(4):
			r = node.r + dr[_]
			c = node.c + dc[_]
			_node = Node(r, c)
			if _node.isValid() and graph[r][c] == '.' and not visited[r][c]:
				q.put(_node)
				visited[r][c] = True
	return False

T = int(input())
while T > 0:
	T -= 1
	R, C = map(int, input().split())
	graph = []
	entrance = []
	for r in range(R):
		graph.append(input())
		for c in range(C):
			if graph[r][c] == '.' and (r == 0 or r == R - 1 or c == 0 or c == C - 1):
				entrance.append(Node(r, c))
	
	if len(entrance) == 2:
		S = entrance[0]
		D = entrance[1]
		if BFS(S, D):
			print('valid')
		else:
			print('invalid')
	else:
		print('invalid')
