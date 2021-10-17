#!/usr/bin/env python3

'''
func Bellman(s, f):
	dist=[-INF,...]x(N+1)
	dist[1]=100
	For i: 1->N-1
		For u,v in edge:
			if dist[v] < dist[u] + energy[v] and dist[u] > 0:
	For u,v in edge:
		if dist[v] < dist[u] + energy[v]:
			if BFS(v,n) == True:
				return True
	return dist[f] > 0

# Each test case: O(V*E + E*E) 
Read(N)
edge=[]
For i: 1->N
	Read(energy[i], adj)
	For j: 1->adj
		Read(u)
		edge.push([i,u])


CanGo = Bellman(1,N)
print('winnable' if CanGo else 'hopeless')
'''

MAX = 105
INF = 1e9

def BellmanFord(s):
  dist[s] = 100
  for i in range(1, N):
    for u,v,w in graph:
      if dist[u] > 0 and dist[v] < w + dist[u]:
        dist[v] = w + dist[u]
        
  for i in range(1, N):
    for u,v,w in graph:
      if dist[u] > 0 and dist[v] < w + dist[u]:
        dist[v] = INF

while True:
  N = int(input())
  if N == -1:
    break
  graph = []
  edges = []
  energies = [0] * (N + 1)
  dist = [-INF] * (N + 1)
  for u in range(1, N + 1):
    line = list(map(int, input().split()))
    energies[u] = line.pop(0)
    
    m = line.pop(0)
    for i in range(m):
      v = line.pop(0)
      edges.append((u,v))
  
  for u,v in edges:
    graph.append((u,v,energies[v]))
  
  BellmanFord(1)
  
  print('winnable' if dist[N] > 0 else 'hopeless')

