#!/usr/bin/env python3

class Node:
	def __init__(self):
		self.countWord = 0
		self.child = {}
	
	def isWord(self):
		return self.countWord > 0

	def isEmpty(self):
		return len(self.child) == 0


def AddWord(root, s):
	temp = root
	for ch in s:
		if ch not in temp.child:
			temp.child[ch] = Node()
		temp = temp.child[ch]
		if temp.isWord() > 0:
			return False
	
	if temp.isEmpty():
		temp.countWord += 1
		return True
	return False
	
vulnerable = True
root = Node()
N = int(input())
for i in range(N):
	s = input()
	if AddWord(root, s) == False:
		print('vulnerable')
		vulnerable = False
		break

if vulnerable == True:
	print('non-vulnerable')

