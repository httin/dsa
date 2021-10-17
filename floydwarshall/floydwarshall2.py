#!/usr/bin/env python3

INF = 10 ** 9
MAX = 26

def FloydWarshall(dist):
	for k in range(V):
		for i in range(V):
			for j in range(V):
				if dist[i][k] != INF and dist[k][j] != INF and \
				dist[i][j] > dist[i][k] + dist[k][j]:
					dist[i][j] = dist[i][k] + dist[k][j]

while True:
	V = int(input())
	if V == 0:
		break
	
	distY = [[0 if i == j else INF for i in range(MAX)] for j in range(MAX)]
	distM = [[0 if i == j else INF for i in range(MAX)] for j in range(MAX)]
	
	for _ in range(V):
		age, dir, x, y, c = input().split()
		u,v = map(lambda char: ord(char) - ord('A'), (x,y))
		c = int(c)
		if age == 'Y':
			distY[u][v] = min(distY[u][v], c)
			if dir == 'B':
				distY[v][u] = min(distY[v][u], c)
		if age == 'M':
			distM[u][v] = min(distM[u][v], c)
			if dir == 'B':
				distM[v][u] = min(distM[v][u], c)
	
	s,f = map(lambda char: ord(char) - ord('A'), input().split())
	
	FloydWarshall(distY)
	FloydWarshall(distM)
	
	res = INF
	arg = 27
	for i in range(MAX):
		if distY[s][i] != INF and distM[f][i] != INF:
			res = min(res, distY[s][i] + distM[f][i])
			arg = i
	if res != INF:
		print(res, chr(ord('A') + arg))
	else:
		print('You will never meet.')
