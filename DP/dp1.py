"""
    Author - Devesh 
    Problem - https://www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/
    Topic - DP
"""

def totalWays(s):
    if s == 0:
        return 1
    if s <= -1:
        return 0
    return totalWays(s-1) + totalWays(s-2) + totalWays(s-3)

print(totalWays(int(input())))
