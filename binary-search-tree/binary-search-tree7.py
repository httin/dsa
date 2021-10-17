#!/usr/bin/env python3
import collections

T = int(input())

input()
while T > 0:
	species = collections.defaultdict(int)
	total = 0
	try:
		T -= 1
		
		while True:
			specie = input()
			if specie == '':
				break
			total += 1
			species[specie] += 1
			
		for key in sorted(species.keys()):
			print('%s %.4f'%(key, species[key]*100/total))
		print()
	except EOFError:
		for key in sorted(species.keys()):
			print('%s %.4f'%(key, species[key]*100/total))
