#!/usr/bin/env python3

n, k = map(int, input().split())
k /= 100
a = list(map(int, input().split()))

def get_min_max(a):
  _min = _max = 0
  for i in range(1, len(a)):
    if a[i] < a[_min]:
      _min = i
    if a[i] > a[_max]:
      _max = i
  return _min, _max

def transform_energy(a, m):
	give = 0
	need = 0
	for i in range(len(a)):
		if a[i] > m:
			give += (a[i] - m)*(1 - k)
		elif a[i] < m:
			need += m - a[i]
	# print(give, need, give >= need)
	return give >= need

_min, _max = get_min_max(a)
left = a[_min]
right = a[_max]
i = 30
mid = None
while i > 0:
	i -= 1
	mid = (left + right)/2
	if transform_energy(a, mid):
		left = mid
	else:
		right = mid
print('%.9f'%mid)
