"""
	Author - Devesh
	Topic - GCD/Euclids Extended Algorithm
"""
# Iterative - 1
def gcd(a, b):
	while a!=0 :
		if a > b:
			a, b = b, a%b
		else:
			a, b = a%b, b
	return b

# Iterative - 2
def gcd2(a, b):
	while b!=0:
		r = a - b*(a//b)	# Remainder
		b, a = r, b
	return a

# Recursive
def gcd(a, b):
	if a == 0:
		return b
	return gcd(b%a, a)

def egcd(a,b):
	if a == 0:
		return (b, 1, 0)
	g, x, y = egcd(b%a, a)
	return (g, y, x-y*(b//a))

print(gcd(10, 16))
print(gcd2(10, 16))
print(egcd(16, 10))
