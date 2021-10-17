#!/usr/bin/env python3

import collections

s = input()
t = input()

d = collections.defaultdict(int)
for i in range(len(s)):
	d[ord(s[i])] += 1

yay = whoops = 0
for i in range(len(t)):
	if ord(t[i]) in d:
		if d[ord(t[i])] > 0:
			yay += 1
			d[ord(t[i])] -= 1
	elif i < len(s) and s[i] != t[i] and s[i].lower() == t[i].lower():
		whoops += 1

print(yay, whoops)
