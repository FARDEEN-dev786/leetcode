class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
    int n = text1.size();
    int m = text2.size();
    int i,j;
    vector<vector<int>> dp(n+1);
    for(i = 0; i <=n;i++){
        vector<int> t(m+1);
        dp[i] = t;
    }
    for(i = 0; i <=n;i++) dp[i][m]=0;
    for(j=0;j<=m;j++) dp[n][j]=0;
    for(i=n-1;i>=0;i--){
        for(j =m-1;j>=0;j--){
            if(text1[i]==text2[j]){
                dp[i][j] = 1+ dp[i+1][j+1];
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}


int minDistance(string word1, string word2) {
    int lcslength = longestCommonSubsequence(word1,word2);
    int ans1 =0;
    ans1 += word1.size() - lcslength;
    ans1+= word2.size()- lcslength;
    return ans1;
}
};