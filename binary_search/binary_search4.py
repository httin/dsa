#!/usr/bin/env python3

def first_lower(a, left, right, x):
	pos = right
	while left <= right:
		mid = left + (right - left)//2
		if a[mid] >= x:
			right = mid - 1
			pos = right
		else:
			left = mid + 1
	return a[pos] if pos != -1 else 'X'

def first_upper(a, left, right, x):
	_right = right
	pos = left
	while left <= right:
		mid = left + (right - left)//2
		# print(left, mid, right)
		if a[mid] <= x:
			left = mid + 1
			pos = left
		else:
			right = mid - 1
	return a[pos] if pos <= _right else 'X'

N = int(input())
a = list(map(int, input().split()))
Q = int(input())
q = list(map(int, input().split()))

for i in range(Q):
	print(first_lower(a, 0, N-1, q[i]), first_upper(a, 0, N-1, q[i]))
	
