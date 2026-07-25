class Solution {
public:
    int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int k = 2;
    int i, j;
    vector<vector<int>> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        vector<int> t(k + 1, -1);
        dp[i] = t;
    }
    for (i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (j = 0; j <= k; j++)
        dp[n][j] = 0;
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 1; j <= k; j++)
        {
            if (j == 2)
            {
                int c1 = dp[i + 1][j - 1] - prices[i];
                int c2 = dp[i + 1][j];
                dp[i][j] = max(c1, c2);
            }
            else
            {
                int c1 = dp[i + 1][2] + prices[i] -fee;
                int c2 = dp[i + 1][j];
                dp[i][j] = max(c1, c2);
            }
        }
    }
    return dp[0][2];
}
};