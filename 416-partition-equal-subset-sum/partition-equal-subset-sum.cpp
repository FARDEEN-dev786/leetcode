class Solution {
public:
    bool subsetsum(vector<int>&a,int sum){
    int n = a.size();
    int i,j;
    vector<vector<bool>>dp(n+1);
    for ( i = 0; i <= n ; i++)
    {
        vector<bool>t(sum+1,false);
        dp[i] = t;
    }
    for(j =0;j<=sum;j++){
        dp[n][j] = false;
    }
    dp[n][0] =true;
    for(i=n-1;i>=0; i--){
        for(j=0; j<=sum; j++){
            if(a[i]>j) dp[i][j] = dp[i+1][j];
            else dp[i][j] = dp[i+1][j-a[i]] || dp[i+1][j];
        }
    }
    return dp[0][sum];
    
}

bool canPartition(vector<int>& nums) {
    int totalsum = 0;
    for(int i = 0; i<nums.size();i++){
        totalsum+=nums[i];
    }
    if(totalsum%2==1) return false;
    return subsetsum(nums,totalsum/2);
}
};