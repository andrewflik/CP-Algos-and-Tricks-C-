"""
    Author - Devesh
    Topic - Dearrangement
    HackerEarth Problem
"""
mod = 1000000007
def solve(n):
	d = [0] * (n+2)
	d[0] = 1
	d[1] = 0
	d[2] = 1
	for i in range(3, n+2):
		d[i] = ((i-1)%mod*(d[i-1]%mod + d[i-2]%mod)%mod)%mod
	return d[n]%mod

n = int(input())
s = input()
if n!=1:
    print(solve(n))
else:
    print(1)
