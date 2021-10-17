#!/usr/bin/env python3

def binary_first_search(a, x):
	left = 0
	right = len(a) - 1
	while left <= right:
		mid = (left + right)//2
		if (mid == left or x > a[mid-1]) and a[mid] == x:
			return mid + 1
		elif a[mid] < x:
			left = mid + 1
		else:
			right = mid - 1
	return -1

case = 1
while True:
	N, Q = map(int, input().split())
	if N == 0 and Q == 0:
		break
		
	print('CASE# {}:'.format(case))
	case += 1
	a = []
	for _ in range(N):
		a.append(int(input()))
	a.sort()
	
	for _ in range(Q):
		x = int(input())
		res = binary_first_search(a, x)
		if res != -1:
			print('{} found at {}'.format(x, res))
		else:
			print('{} not found'.format(x))
	
