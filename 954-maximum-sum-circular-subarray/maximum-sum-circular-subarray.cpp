class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums)
{
    int bestendmax = nums[0];
    int bestendmin = nums[0];
    int maxans = nums[0];
    int minans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int maxv1 = bestendmax + nums[i];
        int v2 = nums[i];
        int minv1 = bestendmin + nums[i];
        bestendmax = max(maxv1, v2);
        bestendmin = min(minv1, v2);
        maxans = max(maxans, bestendmax);
        minans = min(minans, bestendmin);
    }
    if (maxans < 0) return maxans;
    int a2 = sum_of(nums) - minans;
    return max(maxans, a2);
}

int sum_of(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
    }
    return sum;
}
};