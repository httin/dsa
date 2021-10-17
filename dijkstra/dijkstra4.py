#!/usr/bin/emv python3

import queue

INF = 1000000000

def dijkstra(s, dist, graph):
  pq = queue.PriorityQueue()
  
  dist[s] = 0
  pq.put((0,s))
  while not pq.empty():
    w, u = pq.get()

    if dist[u] != w:
      continue
    for cost, v in graph[u]:
      if dist[v] > dist[u] + cost:
        dist[v] = dist[u] + cost
        pq.put((dist[v], v))

T = int(input())
while T>0:
  T -= 1
  V,E,K,s,t = map(int, input().split())
  graph_s = [[] for _ in range(V + 1)]
  graph_t = [[] for _ in range(V + 1)]
  dist_s = [INF]*(V + 1)
  dist_t = [INF]*(V + 1)
  
  for _ in range(E):
    d,c,l = map(int, input().split())
    graph_s[d].append((l,c))
    graph_t[c].append((l,d))
  
  dijkstra(s, dist_s, graph_s)
  dijkstra(t, dist_t, graph_t)
  
  res = dist_s[t]
  for _ in range(K):
    u,v,q = map(int, input().split())
    res = min(res, dist_s[u] + dist_t[v] + q, dist_s[v] + dist_t[u] + q)
  print(res if res != INF else -1)      
  
