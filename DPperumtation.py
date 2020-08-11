"""
    Author - Devesh
    Problem - https://codeforces.com/contest/1091/problem/D
"""
mod = 998244353

n = int(input())
if n == 1:
	print(1)
	exit()
if n == 2:
	print(2)
	exit()

l = [None] * (n+1)
l[1] = 1
l[2] = 2
l[3] = 9
f = 6
for i in range(4, n+1):
	f = (f * i)%mod 
	l[i] = f%mod + (i*(l[i-1]-1))%mod

print(l[n]%mod)
