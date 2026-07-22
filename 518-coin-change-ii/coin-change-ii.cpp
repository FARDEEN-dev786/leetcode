class Solution {
public:
    int change(int amount, vector<int> &coins)
{
    const long long CAP = 2'000'000'000LL;
    int n = coins.size();
    vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

    for (int t = 0; t <= amount; t++)
        dp[0][t] = (t % coins[0] == 0);

    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= amount; t++)
        {
            long long nottake = dp[ind - 1][t];
            long long take = 0;
            if (coins[ind] <= t)
                take = dp[ind][t - coins[ind]];
            dp[ind][t] = min(take + nottake, CAP);   // clamp here
        }
    }
    return (int)dp[n - 1][amount];
}
};