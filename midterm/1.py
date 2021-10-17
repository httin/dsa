#!/usr/bin/env python3

import heapq
import collections

class Node:
	def __init__(self, prio, i):
		self.prio = prio
		self.i = i
	def __lt__(self, other):
		return self.prio > other.prio

T = int(input())
while T > 0:
	T -= 1
	n,m = map(int, input().split())
	l = list(map(int, input().split()))
	pq = []
	dq = collections.deque()
	for i in range(n):
		# node = Node(l[i], i)
		heapq.heappush(pq, Node(l[i], i))
		dq.append(Node(l[i], i))
	
	cnt = 0
	while True:
		top = heapq.heappop(pq)
		node = None
		while True:
			node = dq.popleft()
			print('top: ({}, {}) - node: ({}, {})'.format(top.prio, top.i, node.prio, node.i))
			if node.prio < top.prio:
				dq.append(node)
			else:
				cnt += 1
				break
		if node != None and node.i == m:
			break
	print(cnt)
