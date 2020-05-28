"""
	Author - Devesh
	Problem - https://www.spoj.com/problems/COINS/
	Topic - O(n)
"""
dp = {}
def solve(n):
    if n in dp:
        return dp[n]
    if n == 0:
        return 0
    else:
    	dp[n] = max(n, solve(n//2) + solve(n//3) + solve(n//4))
    	return dp[n]

try:
    while True:
        n = int(input())
        print(solve(n))
except:
    pass
