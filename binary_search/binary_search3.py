#!/usr/bin/env python3

def sum_of_all_heights(a, h):
	res = 0
	for e in a:
		res += max(e - h, 0)
	return res

def binary_search(a):
	left = 0
	right = max(a)
	while left <= right:
		mid = left + (right - left)//2
		woods = sum_of_all_heights(a, mid)
		print(mid, woods)
		if woods == M or left == mid:
			return mid
		elif woods > M:
			left = mid
		else:
			right = mid
	return -1
	

N, M = map(int, input().split())
a = list(map(int, input().split()))

print(binary_search(a))
