#!/usr/bin/env python

a = 2 ** 1000
b = 0
s = str(a)
for c in s:
  b += int(c)
print b
