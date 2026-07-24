class Solution {
public:
    int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    if(n==0) return m;
    if(m==0) return n;
    vector<int>curr(m+1,0);
    vector<int>next(m+1,0);
    for (int j = 0; j <=m; j++)
    {
        next[j]=m-j;
    }
    for (int i = n-1; i >=0; i--)
    {
        curr[m] = n-i;
        for (int j = m-1; j >=0; j--)
        {
            if (word1[i] == word2[j])
                curr[j] = next[j+1];
            else
            {
                int c1 = next[j+1];
                int c2 = curr[j+1];
                int c3 = next[j];
                curr[j] = 1 + min(c1, min(c2, c3));
            }
        }
        next = curr;
    }

    return curr[0];
}
};