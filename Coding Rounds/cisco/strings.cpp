// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

int fmd(int l, int r, vector<vector<int>> dp, string s)
{
 
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (dp[l][r] != 0)
        return dp[l][r];
 
    int res = 1 + fmd(l + 1, r, dp, s);
 
    
    for (int i = l + 1; i <= r; ++i) 
    {
        if (s[l] == s[i])
            res = min(res, fmd(l + 1, i - 1, dp, s)
                               + fmd(i, r, dp, s));
    }
 
    return dp[l][r] = res;
}
 
 
// Driver code
int getmindeletions(string series)
{
   
}