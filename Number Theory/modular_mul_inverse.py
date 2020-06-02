"""
	Modular Multipicatie Inverse
	using Euclids Extended Algo
	Author - Devesh
"""

def egcd(a, b):
	if a == 0:
		return (b, 0, 1)
	g, x, y = egcd(b%a, a)
	return (g, y-x*(b//a), x)

def findInverse(g, x, m):
 	if g!=1:
 		print("Doesnt Exist")
 		return
 	return (x%m+m)%m


m = 11
t = egcd(3, m)
print(findInverse(t[0], t[1], m))
