class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if(nums.size()<4){
            return result;
        }
        for (int j = 0; j < nums.size() - 3; j++) {
            if (j > 0 && nums[j] == nums[j - 1]) {
                continue;
            }
            long long newsum = (long long)target - nums[j];
            for (int i = j + 1; i < nums.size() - 2; i++) {
                if (i > j + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                long long sum = newsum - nums[i];
                while (left < right) {
                    long long s = (long long)nums[left] + nums[right];
                    if (s == sum) {
                        result.push_back(vector<int>{nums[j], nums[i],
                                                     nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (s < sum) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};