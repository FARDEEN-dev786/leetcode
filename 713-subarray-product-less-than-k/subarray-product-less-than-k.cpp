class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        if (k <= 1) return 0;
    int low = 0;
    int high = 0;
    int ans=0;
    int n = nums.size();
    int product = 1;
    for (high  = 0; high < n; high++)
    {
        product = product*nums[high];
        while (product>=k)
        {
            product = product/nums[low];
            low++;
        }
        ans= ans + high -low+1;
    }
    return ans;  
}
};