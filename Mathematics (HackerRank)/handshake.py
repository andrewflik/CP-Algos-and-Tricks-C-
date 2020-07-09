"""
    Author - Devesh
    Problem - HandShake
    Application - HandShake Lemma
"""

n = int(input())
while n:
    t = int(input())
    print((t*(t-1))//2)
    n -= 1
