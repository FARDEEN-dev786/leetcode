class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size()-2; i++)
    {
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int left = i+1;
        int right = nums.size()-1;
        int newsum = -1*nums[i];
        while (left<right)
        {
            if(nums[left]+nums[right]==newsum){
                ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                left++;
                right--;
                while (left<nums.size() && nums[left]==nums[left-1])
                {
                    left++;
                }
                while (right>=0 && nums[right]==nums[right+1])
                {
                    right--;
                }
                
            }
            else if(nums[left]+nums[right]<newsum){
                left++;
            }
            else{
                right--;
            }
        }
        
    }
    return ans;
}
};