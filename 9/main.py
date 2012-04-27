#!/usr/bin/env python


# integer sqrt
def isqrt(x):
	for i in range (x/2, 0, -1):
		if x == i * i:
			return i
	return -1


def main():
	for a in range(2, 500):
		for b in range(a-1, 2, -1):
			c = isqrt(a * a + b * b)
			if -1 == c:
				continue
		
			if 1000 == a + b + c:
				print '%d %d %d %d' % (a, b, c, a * b * c)
				return

main()
