#!/usr/bin/env python3

def ladder(a, x):
	if a[0] == x:
		x -= 1
	for i in range(0, n - 1):
		delta = a[i + 1] - a[i]
		if delta == x:
			x -= 1
		elif delta > x:
			return -1
	return x

def binary_search(a, left, right):
	res = left
	while left < right:
		mid = left + (right - left)//2
		k = ladder(a, mid)
		# print(left, right, mid, k)
		if k == -1:
			left = mid + 1
			res = left
		elif k == mid:
			right = mid
			res = right
		elif k < mid:
			return mid
	return res

T = int(input())
for t in range(1, T+1):
	n = int(input())
	r = list(map(int, input().split()))
	
	print('Case {}: {}'.format(t, binary_search(r, r[0], r[-1])))
