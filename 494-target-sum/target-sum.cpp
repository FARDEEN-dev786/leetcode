class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalsum += nums[i];
        }
        if (abs(target) > totalsum)
            return 0;

        if ((totalsum + target) % 2 != 0)
            return 0;
        
        return perfectSum(nums, (target + totalsum) / 2);
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int i, j;
        vector<vector<int>> dp(n + 1);
        for (int i = 0; i <= n; i++) {
            vector<int> t(target + 1, 0);
            dp[i] = t;
        }
        for (j = 0; j <= target; j++) {
            dp[0][j] = 0;
        }
        dp[n][0] = 1;
        for (i = n - 1; i >= 0; i--) {
            for (j = 0; j <= target; j++) {
                if (arr[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = (dp[i + 1][j - arr[i]]) + (dp[i + 1][j]);
                }
            }
        }
        return dp[0][target];
    }
};