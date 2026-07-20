class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if(obstacleGrid[n-1][m-1] ==1) return 0;
    vector<vector<int>>dp(n+1);
    for(int i=0;i<=n;i++){
        vector<int>t(m+1,-1);
        dp[i] = t;
    }
    return fun(0,0,n,m,dp,obstacleGrid);

}

int fun(int i, int j,int n, int m,vector<vector<int>>& dp, vector<vector<int>>&obstacle){
    if(i==n-1 && j==m-1) return 1;
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    if(obstacle[i][j]==1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = fun(i+1,j,n,m,dp,obstacle)+fun(i,j+1,n,m,dp,obstacle);
}
};