#!/usr/bin/env python3

n = int(input())
l = input()
s = {'a','b','c','d','e','f','g','h','i','j','k','l',
     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
res = False
for c in l:
	c = c.lower()
	if c in s:
		s.remove(c)
	if not s:
		res = True
		break

if res == True:
	print('YES')
else:
	print('NO')
