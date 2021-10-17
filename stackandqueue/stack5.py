#!/usr/bin/env python3

molecule = input()

atomics = [0]*3 # C=0, O=1, H=2
stack = []
res = 0
cur = 0
for i in range(len(molecule)):
	if molecule[i] == 'C':
		cur = 12
	elif molecule[i] == 'H':
		cur = 1
	elif molecule[i] == 'O':
		cur = 16
	elif molecule[i].isnumeric():
		cur *= (int(molecule[i]) - 1)
	elif molecule[i] == '(':
		stack.append(res)
		res = 0
		continue
	elif molecule[i] == ')':
		cur = res
		res += stack.pop()
		continue
	res += cur
print(res)
