class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k)
{
    int numberofodds = 0;
    int low = 0;
    int high = 0;
    int middle = 0;
    int n = nums.size();
    int ans = 0;
    for (int high = 0; high < n; high++)
    {
        if (nums[high] % 2 != 0)
        {
            numberofodds += 1;
        }

        while (numberofodds > k)
        {
            if (nums[low] % 2 != 0)
            {
                numberofodds--;
            }
            low++;
            middle=low;
        }

        if (numberofodds == k)
        {
            while(nums[middle]%2==0){
                middle++;
            }
            ans += middle-low+1;
        }
    }
    return ans;
}
};