#!/usr/bin/env python3

h = []
indexOf = {}

def parent(i):
	return (i - 1)//2

def minHeapify(h, i):
	left = 2*i + 1
	right = 2*i + 2
	smallest = i
	if left < len(h) and h[left] < h[smallest]:
		smallest = left
	if right < len(h) and h[right] < h[smallest]:
		smallest = right
	if smallest != i:
		h[i], h[smallest] = h[smallest], h[i]
		indexOf[h[smallest]] = smallest
		indexOf[h[i]] = i
		minHeapify(h, smallest)

def push(h, val):
	h.append(val)
	i = len(h) - 1
	indexOf[val] = i
	while i != 0:
		j = parent(i)
		if h[j] > h[i]:
			h[i], h[j] = h[j], h[i]
			indexOf[h[i]] = i
			indexOf[h[j]] = j
			i = j
		else:
			break

def pop(h):
	length = len(h)
	if length == 0:
		return
	indexOf.pop(h[0]) # remove top from index-dictionary
	h[0] = h[length - 1]
	indexOf[h[0]] = 0
	h.pop()
	minHeapify(h, 0)

def erase(h, val):
	k = indexOf.pop(val)
	last = len(h) - 1
	if k == last:
		h.pop()
		return
	h[k] = h[last]
	indexOf[h[last]] = k
	h.pop()
	if k == 0 or h[k] > h[parent(k)]:
		# heap-down
		minHeapify(h, k)
	else:
		# heap-up
		while k != 0 and h[parent(k)] > h[k]:
			h[k], h[parent(k)] = h[parent(k)], h[k]
			indexOf[h[k]] = k
			indexOf[h[parent(k)]] = parent(k)
			k = parent(k)

def top(h):
  return h[0]
  
Q = int(input())
while Q > 0:
	Q -= 1
	q = list(map(int, input().split()))
	if q[0] == 1:
		push(h, q[1])
		print(h, indexOf)
	elif q[0] == 2:
		erase(h, q[1])
		print(h, indexOf)
	elif q[0] == 3:
		print(h[0])
