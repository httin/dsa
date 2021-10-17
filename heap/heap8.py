#!/usr/bin/env python3
import heapq

class Job:
	def __init__(self, a, b, d):
		self.a = a
		self.b = b
		self.d = d
	def __lt__(self, other):
		return self.a > other.a
'''
jobs[i] = [a[i] b[i] d[i]]
sort(jobs, d)
heap = max_heap(a)
time = 0
money = 0.0

for i = 1:N
	time += jobs[i].b
	heap.push(jobs[i])
	while time > jobs[i].d
		top = heap.top()
		heap.pop()
		diff = time - jobs[i].d
		
		if top.b > diff
			top.b -= diff
			time -= diff
			money += diff/top.a
			heap.push(top)
		else
			money += top.b/top.a
			time -= top.b
	
	print("{:2.f}".format(money))
'''
T = int(input())
while T > 0:
	T -= 1
	N = int(input())
	jobs = []
	for i in range(N):
		a,b,d = map(int, input().split())
		jobs.append(Job(a,b,d))
	jobs.sort(key = lambda x: x.d)
	# for job in jobs:
		# print('({},{},{})'.format(job.a,job.b,job.d))
	# for job in maxheap:
		# print('({},{},{})'.format(job.a,job.b,job.d))

	time = 0
	money = 0.0
	maxheap = []
	for i in range(N):
		time += jobs[i].b
		heapq.heappush(maxheap, jobs[i])

		while time > jobs[i].d:
			diff = time - jobs[i].d
			top = heapq.heappop(maxheap)
			if diff < top.b:
				top.b -= diff
				time -= diff
				money += diff/top.a
				heapq.heappush(maxheap,top)
			else:
				money += top.b/top.a
				time -= top.b
	print("%.2f"%(money))
				
