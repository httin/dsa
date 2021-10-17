#!/usr/bin/env python3

n = int(input())

MAX = 1000

parent = [None for x in range(MAX**2 + 1)]
ranks = [0 for x in range(MAX**2 + 1)]
xCoordinates = [[] for x in range(MAX + 1)]
yCoordinates = [[] for y in range(MAX + 1)]

def getID(x,y):
  return (MAX - 1)*x + y

def getCoor(id):
  return id//(MAX-1) + 1, id % (MAX-1)

def findSet(id):
  if id != parent[id]:
    parent[id] = findSet(parent[id])
  return parent[id]

ans = n
def unionSet(u, v):
  global ans
  pu = findSet(u)
  pv = findSet(v)
  if pu == pv:
    return
  if ranks[pu] > ranks[pv]:
    parent[pv] = pu
  elif ranks[pu] < ranks[pv]:
    parent[pu] = pv
  else:
    parent[pu] = pv
    ranks[pv] += 1
  ans -= 1

for _ in range(n):
  x,y = map(int, input().split())
  id = getID(x,y)
  parent[id] = id
  xCoordinates[x].append(y)
  yCoordinates[y].append(x)

for x in range(0, MAX):
  if len(xCoordinates[x]) > 1:
    # print('xCoordinates={}'.format(xCoordinates[x]))
    for i in range(1, len(xCoordinates[x])):
      id1 = getID(x, xCoordinates[x][0])
      id2 = getID(x, xCoordinates[x][i])
      unionSet(id1, id2)
      
for y in range(0, MAX):
  if len(yCoordinates[y]) > 1:
    # print('yCoordinates={}'.format(yCoordinates[y]))
    for i in range(1, len(yCoordinates[y])):
      id1 = getID(yCoordinates[y][0], y)
      id2 = getID(yCoordinates[y][i], y)
      unionSet(id1, id2)

print(ans - 1)
