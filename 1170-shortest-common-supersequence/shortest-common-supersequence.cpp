class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int i, j;
        vector<vector<int>> dp(n + 1);
        for (i = 0; i <= n; i++) {
            vector<int> t(m + 1);
            dp[i] = t;
        }
        for (i = 0; i <= n; i++)
            dp[i][m] = 0;
        for (j = 0; j <= m; j++)
            dp[n][j] = 0;
        for (i = n - 1; i >= 0; i--) {
            for (j = m - 1; j >= 0; j--) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        string ans = "";
        // extra for SCS
        i = 0;
        j = 0;
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else if (dp[i + 1][j] > dp[i][j + 1]) {
                ans += str1[i];
                i++;
            } else {
                ans += str2[j];
                j++;
            }
        }
        while (i < n) {
            ans += str1[i++];
        }

        while (j < m) {
            ans += str2[j++];
        }
        return ans;
    }
};