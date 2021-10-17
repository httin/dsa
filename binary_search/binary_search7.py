#!/usr/bin/env python3

def binary_search(a, left, right, x):
	while left <= right:
		mid = left + (right - left)//2
		if a[mid] < x:
			left = mid + 1
		elif a[mid] > x:
			right = mid - 1
		else:
			return mid
	return -1

n,k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

res = 0
for i in range(n):
	target = a[i] + k
	
	right = binary_search(a, i, n - 1, target) 
	if right != -1:
		res += 1

print(res)
