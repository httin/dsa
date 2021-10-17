#!/usr/bin/env python3

k,n,w = map(int, input().split())

res = k*w*(w+1)//2 - n

if res < 0:
	print(0)
else:
	print(res)
