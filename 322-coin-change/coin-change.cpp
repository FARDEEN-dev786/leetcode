class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n+1);
    for(int i=0;i<=n;i++)
    {
        vector<int>t(amount+1,-1);
        dp[i]=t;
    }
    int ans= fun(coins.size()-1,amount,coins,dp);
    if(ans>=1e9) return -1;
    return ans;
}

int fun(int ind, int amount, vector<int>& coins,vector<vector<int>>&dp){
    if(ind==0){
        if(amount%coins[ind]==0) return amount/coins[ind];
        else return 1e9;
    }
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int nottake = 0 + fun(ind-1,amount,coins,dp);
    int take = INT_MAX;
    if(coins[ind]<=amount) take = 1+fun(ind,amount-coins[ind],coins,dp);
    return dp[ind][amount] = min(take,nottake);
}
};