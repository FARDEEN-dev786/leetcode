class Solution {
public:
    int fun(int i, int j,int n, int m,vector<vector<int>>& dp){
    if(i==n-1 && j==m-1) return 1;
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = fun(i+1,j,n,m,dp)+fun(i,j+1,n,m,dp);
}
int uniquePaths(int m, int n){
    vector<vector<int>>dp(n+1);
    for(int i=0;i<=n;i++){
        vector<int>t(m+1,-1);
        dp[i] = t;
    }
    return fun(0,0,n,m,dp);
}
};