class Solution {
public:
    int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // vector<vector<long long>> dp(n + 1);
    vector<double> prev(m+1,0);
    vector<double> next(m+1,0);

    
    prev[m]=1;

    for (int i = n - 1; i >= 0; i--)
    {
        next[m]=1;
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
            {
                //dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                next[j] = prev[j+1] + prev[j];
            }
            else
            {
                //dp[i][j] = dp[i + 1][j];
                next[j] = prev[j];
            }
        }
        prev = next;
    }
    //return dp[0][0];
    return next[0];
}
};