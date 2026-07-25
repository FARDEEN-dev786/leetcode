class Solution {
public:
    int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int k = 2;
    int i, j;
    vector<int>next(3);
    vector<int>curr(3);

    for(int i = 0;i<=2;i++) next[i] = 0;
    
    for (i = n - 1; i >= 0; i--)
    {
        curr[0] = 0;
        for (j = 1; j <= k; j++)
        {
            if (j == 2)
            {
                int c1 = next[j - 1] - prices[i];
                int c2 = next[j];
                curr[j] = max(c1, c2);
            }
            else
            {
                int c1 = next[2] + prices[i] -fee;
                int c2 = next[j];
                curr[j] = max(c1, c2);
            }
        }
        next = curr;
    }
    return next[2];
}
};