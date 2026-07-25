class Solution {
public:
    bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        vector<int> t(m + 1, -1);
        dp[i] = t;
    }

    dp[n][m] = 1;
    for (int i = 0; i < n; i++)
        dp[i][m] = 0;
    for (int j = m - 1; j >= 0; j--)
    {
        if (p[j] == '*')
            dp[n][j] = dp[n][j + 1];
        else
            dp[n][j] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == p[j] || p[j] == '?')
                dp[i][j] = dp[i + 1][j + 1];

            else if (p[j] == '*')
            {
                dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return dp[0][0];
}
};