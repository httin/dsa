#!/usr/bin/env python3

dr = [0,0,1,-1]
dc = [1,-1,0,0]

def isBorder(i, j):
	return i == 0 or i == n-1 or j == 0 or j == m-1
	
def isValid(i, j):
	return i >= 0 and i < n and j >= 0 and j < m

def dfs(s):
	visited[s[0]][s[1]] = True
	q = [s]
	
	isOcean = isBorder(s[0], s[1])
	lake = [s]
	
	while len(q):
		x, y = q.pop()
		for i in range(4):
			r = x + dr[i]
			c = y + dc[i]
			if isValid(r,c) and not visited[r][c] and graph[r][c] == '.':
				visited[r][c] = True
				lake.append((r,c))
				q.append((r,c))
				if isBorder(r, c):
					isOcean = True
					
	if not isOcean:
		lakes.append(lake)
	

n,m,k = map(int, input().split())

graph = []
for i in range(n):
	graph.append(list(input()))

visited = [[False for i in range(m)] for j in range(n)]

lakes = []
for i in range(n):
	for j in range(m):
		if graph[i][j] == '.' and not visited[i][j]:
			dfs((i,j))
				
lakes.sort(key=lambda x: len(x))

res = 0
for i in range(len(lakes) - k):
	lake = lakes[i]
	res += len(lake)
	for r,c in lake:
		graph[r][c] = '*'

print(res)
for i in range(n):
	for j in range(m):
		print(graph[i][j],end='')
	print()
