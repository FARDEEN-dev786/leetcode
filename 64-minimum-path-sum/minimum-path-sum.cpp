class Solution {
public:
    int minPathSum(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n+1);
    for(int i=0;i<=n;i++){
        vector<int>t(m+1,-1);
        dp[i] = t;
    }
    
    return fun(0,0,n,m,dp,grid);
}
int fun(int i , int j, int n, int m, vector<vector<int>>&dp,vector<vector<int>>&grid){
    if(i==n-1 && j==m-1) return grid[i][j];
    if(i<0 || i>=n || j<0 || j>=m) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int c1 = fun(i+1,j,n,m,dp,grid) +grid[i][j];
    int c2 = fun(i,j+1,n,m,dp,grid) +grid[i][j];
    return dp[i][j] = min(c1,c2);
}
};