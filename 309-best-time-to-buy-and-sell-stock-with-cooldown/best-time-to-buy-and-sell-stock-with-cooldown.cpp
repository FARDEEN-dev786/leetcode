class Solution {
public:
    int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int k = 2;
    int i, j, flag;
    vector<vector<vector<int>>> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        vector<vector<int>> t(k + 1, vector<int>(2, -1));
        dp[i] = t;
    }
    for (i = 0; i <= n; i++)
    {
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
    }
    for (j = 0; j <= k; j++)
    {
        dp[n][j][0] = 0;
        dp[n][j][1] = 0;
    }

    for (i = n - 1; i >= 0; i--)
    {
        for (j = 1; j <= k; j++)
        {
            for (int flag = 0; flag <= 1; flag++)
            {
                if (flag == 1)
                    dp[i][j][flag] = dp[i + 1][j][0];
                else if (j == 2)
                {
                    int c1 = dp[i + 1][j - 1][0] - prices[i];
                    int c2 = dp[i + 1][j][0];
                    dp[i][j][flag] = max(c1, c2);
                }
                else
                {
                    int c1 = dp[i + 1][2][1] + prices[i];
                    int c2 = dp[i + 1][j][0];
                    dp[i][j][flag] = max(c1, c2);
                }
            }
        }
    }
    return dp[0][2][0];
}
};