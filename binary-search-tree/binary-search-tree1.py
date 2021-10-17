#!/usr/bin/env python3

T = int(input())
while T > 0:
	T -= 1
	n, x = map(int, input().split())
	A = list(map(int, input().split()))
	s = set()
	for a in A:
		s.add(a)
	if len(s) < x:
		print('Bad')
	elif len(s) == x:
		print('Good')
	else:
		print('Average')
