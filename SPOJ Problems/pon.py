"""
	Author - Devesh
	Problem - PON (SPOJ)
  Topic - Fermats Little Theorem
"""
import math
import random
# randint()
def binMul(a, p, m):
	if(p == 1):
		return a%m
	res = 1
	while(p):
		if(p&1):
			res = (res%m * a%m)%m
		a = (a%m * a%m)%m
		p = p >> 1
	return res%m

def gcd(a, b):
	if b==0:
		return a
	return gcd(b, a%b)

def fpt(n):
	if n <= 4:
		if n==2:
			return True
		if n==3:
			return True
		return False

	for i in range(4, 25):
		a = random.randint(3, n-1)
		if(gcd(a, n)!=1):
	#		print("GCD")
			return False
		if(binMul(a, n-1, n)!=1):
	#		print("BIN")
			return False
	return True
	
t = int(input())
while t > 0:
	t = t-1
	n = int(input())
	if fpt(n):
		print("YES")
	else:
		print("NO")


