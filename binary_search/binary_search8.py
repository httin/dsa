#!/usr/bin/env python3
import math

LOOPS = 14
eps = 10**(-4)

def df(x):
	global p,q,r,s,t,u
	return -p*math.exp(-x) + q*math.cos(x) - r*math.sin(x) + \
			s/(math.cos(x)*math.cos(x)) + 2*t*x

def f(x):
	global p,q,r,s,t,u
	return p*math.exp(-x) + q*math.sin(x) + \
		   r*math.cos(x) + s*math.tan(x) + t*x*x + u

while True:
	try:
		p,q,r,s,t,u = map(int, input().split())
	except:
		break
	
	try:
		x0 = 0.5
		for i in range(LOOPS):
			x = x0 - f(x0)/df(x0)
			# print('f(x0)={} -> x={}'.format(f(x0), x))
			x0 = x
			
		if abs(f(x0)) < eps and x > -eps and x < 1:
			print('%.4f'%abs(x0))
		else:
			print('No solution')
	except:
		print('No solution')
