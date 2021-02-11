#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n, double val[], double wt[], double &maxValue)
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    if( W == 0)
        return true;
    double maxSoFar = INT_MIN;
    bool foundASeries = false;
    for(int i = 0; i < n; i++)
    {
        if(W >= wt[i])
        {
            maxValue  = 0;
            if(unboundedKnapsack(W-wt[i], n, val, wt, maxValue))
            {
                foundASeries = true;
                maxSoFar = max(maxSoFar, maxValue + val[i]);
            }
        }
    }
    maxValue = maxSoFar;
    return foundASeries;
}

// Driver program
int main()
{
    double val[] = {5, 10, 20, 5.5, 2.5};
    double wt[] = { 90 ,25.5 ,15.5 ,30.8 ,18.8};
    double W = 200;
    double maxValue = 0;
    int n = sizeof(val)/sizeof(val[0]);

    cout << unboundedKnapsack(W, n, val, wt, maxValue)<<endl;
    cout<< "max value is "<<maxValue;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
 
// // Returns the maximum value with knapsack of
// // W capacity
// int unboundedKnapsack(int W, int n, 
//                        double val[], double wt[])
// {
//     // dp[i] is going to store maximum value
//     // with knapsack capacity i.
//     double dp[W+1];
//     memset(dp, 0, sizeof dp);
 
//     // Fill dp[] using above recursive formula
//     for (int i=0; i<=W; i++)
//       for (int j=0; j<n; j++)
//          if (wt[j] <= i)
//             dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
//     return dp[W];
// }
 
// // Driver program
// int main()
// {
//     double val[] = {4.5,2.5,3.1,1.60,0.47};
//     double wt[] = { 90 ,25.5 ,15.5 ,30.8 ,18.8};
//     double W = 200;
//     int n = sizeof(val) / sizeof(val[0]);
//     cout << unboundedKnapsack(W, n, val, wt);
//     return 0;
// }
// /*
// 4 2 100
// 20 10 30 40
// 5 10 30 20
// */
// /*
// 5 3 200
// 90 25.5 15.5 30.8 18.8
// 5 10 20 5.5 2.5
// */