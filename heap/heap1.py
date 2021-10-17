#!/usr/bin/env python3

import heapq

N = int(input())
a = list(map(int, input().split()))
b = []

max1 = max2 = 0
for i in range(N):
	heapq.heappush(b, -a[i])
	if i < 2:
		print(-1)
	else:
		first = -heapq.heappop(b)
		second = -heapq.heappop(b)
		third = -heapq.heappop(b)
		res = first*second*third
		heapq.heappush(b, -first)
		heapq.heappush(b, -second)
		heapq.heappush(b, -third)
		print(res)
