#!/usr/bin/env python3

n = int(input())
median = (n + 1)//2
count = [0 for _ in range(200001)] # [-1e5, 1e5]

for i in input().split():
	count[int(i)] += 1

s = 0
for i in range(-100000, 100001):
	s += count[i]
	if s >= median:
		print(i)
		break
