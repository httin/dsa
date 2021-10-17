#!/usr/bin/env python3

'''
i    : 1   2  3  4  5  6   7
a[i] : 20  7  8  5  2  24  23
p[i] : x   20 20 7  5  x   24
'''

class Node:
	def __init__(self, key = 0):
		self.left = None
		self.right = None
		self.key = key

def InsertNode(root, key):
	if root == None:
		return Node(key)
	elif key < root.key:
		root.left = InsertNode(root.left, key)
	elif key > root.key:
		root.right = InsertNode(root.right, key)
	return root

# find the minimum value greater than x
def upper_bound(root, x):
	if root == None:
		return root
	if root.key <= x:
		return upper_bound(root.right, x)
	else:
		ub_left = upper_bound(root.left, x)
		return root if ub_left is None else ub_left

def CreateBST(a, n):
	root == None
	for i in range(n):
		root = InsertNode(root, a[i])
	return root

n = int(input())
a = list(map(int, input().split()))

res = 10**16
root = None
for i in range(n):
	p_node = upper_bound(root, a[i])
	if p_node is not None:
		res = min(res, p_node.key - a[i])
	root = InsertNode(root, a[i])
print(res)
