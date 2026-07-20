class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
    int n = triangle.size();
    vector<vector<int>>dp(n+1);
    for(int i=0;i<=n;i++){
        vector<int>t(i+1,-1);
        dp[i] = t;
    }
    for (int i = 0; i < n; i++)
    {
        dp[n-1][i] = triangle[n-1][i];
    }
    for(int i =n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            int c1 = dp[i+1][j+1];
            int c2 = dp[i+1][j];
            dp[i][j] = min(c1,c2) + triangle[i][j];
        }
    }
    return dp[0][0];
}
};