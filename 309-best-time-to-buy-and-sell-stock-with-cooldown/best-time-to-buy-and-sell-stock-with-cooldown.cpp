class Solution {
public:
    int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int k = 2;
    vector<vector<vector<int>>> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        vector<vector<int>> t(k + 1, vector<int>(2,-1));
        dp[i] = t;
    }
    int gain = fun(prices, n, 0, k, dp,0);
    return gain;
}

int fun(vector<int> &a, int n, int i, int k, vector<vector<vector<int>>> &dp,int flag)
{
    if (i == n)
        return 0;
    if (k == 0)
        return 0;
    if(flag==1) return dp[i][k][flag]= fun(a,n,i+1,k,dp,0);
    if (dp[i][k][flag] != -1)
        return dp[i][k][flag];

    if (k == 2)
    {
        int c1 = fun(a, n, i + 1, k - 1, dp,0) - a[i];
        int c2 = fun(a, n, i + 1, k, dp,0);
        return dp[i][k][flag] = max(c1, c2);
    }
    else
    {
        int c1 = fun(a, n, i + 1, 2, dp,1) + a[i];
        int c2 = fun(a, n, i + 1, k, dp,0);
        return dp[i][k][flag] = max(c1, c2);
    }
}
};