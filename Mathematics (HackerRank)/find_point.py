""" 
    Author - Devesh
    Problem - Find Point
"""

n = int(input())
while n > 0:
    px, py, qx, qy = map(int, input().split())
    #qx, qy = input().split()
    print(2*qx-px, 2*qy-py)
    n -= 1
