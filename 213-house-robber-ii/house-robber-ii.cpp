class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1)
            return nums[0];
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            vector<int> t(2, -1);
            dp[i] = t;
        }
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        vector<vector<int>> dp2 = dp;
        int ans1 = fun(temp1, n - 1, 0, 1, dp);
        int ans2 = fun(temp2, n - 1, 0, 1, dp2);
        return max(ans1, ans2);
    }

    int fun(vector<int>& nums, int n, int i, int flag,
            vector<vector<int>>& dp) {
        if (i == n)
            return 0;
        if (dp[i][flag] != -1)
            return dp[i][flag];
        if (flag == 0)
            return dp[i][flag] = fun(nums, n, i + 1, 1, dp);

        int c1 = nums[i] + fun(nums, n, i + 1, 0, dp);
        int c2 = fun(nums, n, i + 1, 1, dp);
        return dp[i][flag] = max(c1, c2);
    }
};