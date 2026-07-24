class Solution {
public:
    int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>>dp(n+1);
    for(int i = 0; i<=n;i++){
        vector<int>t(m+1,-1);
        dp[i] = t;
    }
    return fun(0,0,n,m,word1,word2,dp);
}

int fun(int i, int j, int n, int m, string s1, string s2,vector<vector<int>>&dp){
    if(i==n) return m-j;
    if(j==m) return n-i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j] = fun(i+1,j+1,n,m,s1,s2,dp);
    else{
        int c1 = fun(i+1,j+1,n,m,s1,s2,dp);
        int c2 = fun(i+1,j,n,m,s1,s2,dp);
        int c3 = fun(i,j+1,n,m,s1,s2,dp);
        return dp[i][j] = 1+min(c1,min(c2,c3));
    }
}
};