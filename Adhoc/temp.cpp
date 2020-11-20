/* Read input from STDIN. Print your output to STDOUT*/
#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int solve(int s, int e, int maxn, int ar[]){
    if(s == e or (s > e or e < s))
        return maxn;
    // Include both
    maxn += ar[s] * ar[e];
    ans = max(solve(s+1, e, maxn, ar), solve(s, e-1, maxn, ar));
    return ans;
}
int main(int argc, char *a[])
{
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    cout << solve(0, n-1, 0, ar);
}
