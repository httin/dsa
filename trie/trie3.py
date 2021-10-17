#!/usr/bin/env python3

class Node:
	def __init__(self):
		self.countWord = 0
		self.child = dict()

def addWord(root, s):
	global ret
	temp = root
	for ch in s:
		if ch not in temp.child:
			temp.child[ch] = Node();
		temp = temp.child[ch]
		if temp.countWord > 0:
			ret = True
			return
	if len(temp.child) > 0:
		ret = True
	temp.countWord += 1

ret = None
T = int(input())
for t in range(1, T+1):
	N = int(input())
	
	ret = False
	root = Node()
	for i in range(N):
		s = input()
		addWord(root, s)

	print('Case {}: {}'.format(t, 'NO' if ret == True else 'YES'))
