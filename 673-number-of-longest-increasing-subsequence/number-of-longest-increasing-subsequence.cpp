class Solution {
public:
    int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    vector<int> count(n, 1);
    int i, j;
    for (i = 0; i < n; i++)
    {
        res[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (res[j] + 1 > res[i])
                {
                    res[i] = res[j] + 1;

                    count[i] = count[j];
                }
                else if (res[j] + 1 == res[i])
                {
                    count[i] += count[j];
                }
            }
        }
    }
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, res[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (res[i] == maxi)
            ans += count[i];
    }

    return ans;
}
};