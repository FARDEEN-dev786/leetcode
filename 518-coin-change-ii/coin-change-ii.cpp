class Solution {
public:
    int fun(int ind, int t, vector<int> &arr,vector<vector<int>>&dp)
{
    if (ind == 0)
    {
        return (t % arr[0] == 0);
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    int nottake = fun(ind - 1, t, arr,dp);
    int take = 0;
    if (arr[ind] <= t)
        take = fun(ind, t - arr[ind], arr,dp);
    return dp[ind][t] = take + nottake;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>>dp(n+1);
    for (int i = 0; i <= n; i++)
    {
        vector<int> t(amount+1, -1);
        dp[i] = t;
    }
    return fun(n - 1, amount, coins,dp);
}

};