#!/usr/bin/env python3

t = int(input())
while t > 0:
	t -= 1
	n, target = map(int, input().split())
	a = list(map(int, input().split()))
	a.sort()
	res = 0
	p1 = 0
	p2 = n - 1
	# print('CASE# {}:'.format(t))
	while p1 < p2:
		if a[p1] + a[p2] == target:
			res += 1
			p1 += 1
			p2 -= 1
		elif a[p1] + a[p2] > target:
			p2 -= 1
		else:
			p1 += 1
	print(res)
			
