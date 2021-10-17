#!/usr/bin/env python3
'''
1 2 3
'''
import queue

t = 1
while True:
	P,C = map(int, input().split())
	if P == 0 and C == 0:
		break
	print('Case {}:'.format(t))
	q = queue.Queue()
	size = min(P,C)
	for i in range(1, size + 1):
		q.put(i)
	
	for i in range(C):
		c = input().split()
		if c[0] == 'N':
			e = q.get()
			print(e)
			q.put(e)
		else:
			e = int(c[1])
			n = q.qsize()
			q.put(e)
			for j in range(n):
				x = q.get()
				if x != e:
					q.put(x)
	t += 1
