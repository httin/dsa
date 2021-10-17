#!/usr/bin/env python3

import heapq

MAX_BILLS = 10**6

class Bill:
	def __init__(self, id, price):
		self.id = id
		self.price = price
		
	def __lt__(self, other):
		return self.price <= other.price

max_heap = []
min_heap = []

n = int(input()) # [1, 5000]
markedBill = [False] * MAX_BILLS

promo = 0
nbills = 0
for i in range(1, n + 1):
	a = list(map(int, input().split()))
	
	for j in range(1, a[0] + 1):
		heapq.heappush(min_heap, Bill(nbills, a[j]))
		heapq.heappush(max_heap, Bill(nbills, -a[j]))
		nbills += 1
	
	small = None
	while len(min_heap) > 0:
		if not markedBill[min_heap[0].id]:
			small = heapq.heappop(min_heap)
			markedBill[small.id] = True
			break
		heapq.heappop(min_heap)
	
	large = None
	while len(max_heap) > 0:
		if not markedBill[max_heap[0].id]:
			large = heapq.heappop(max_heap)
			markedBill[large.id] = True
			break
		heapq.heappop(max_heap)
		
	if small != None and large != None: 
		promo += -large.price - small.price
print(promo)
