#!/usr/bin/env python3

from queue import Queue

Q = int(input())
while Q > 0:
  Q -= 1
  V,E = map(int, input().split())
  graph = [[] for i in range(V)]
  for i in range(E):
    e = list(map(int, input().split()))
    graph[e[0] - 1].append(e[1] - 1)
    graph[e[1] - 1].append(e[0] - 1)
  visited = [False]*V
  distance = [-1]*V
  
  S = int(input())
  distance[S-1] = 0
  visited[S-1] = True
  q = Queue()
  q.put(S-1)
  
  while not q.empty():
    u = q.get()
    for v in graph[u]:
      if visited[v] == False:
        q.put(v)
        visited[v] = True
        distance[v] = distance[u] + 1
 
  for i in range(V):
    if i != S-1:
      if distance[i] != -1:
        print(distance[i]*6, end=' ')
      else:
        print(-1, end=' ')
  print()
  
  # print(output)
