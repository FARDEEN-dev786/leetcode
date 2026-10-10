class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k){
    int low = 0;
    int high = k-1;
    double sum = 0;
    int n = nums.size();
    double ans = 0;
    for(int i=low;i<=high;i++){
        sum = sum+ nums[i];
    }
    ans = sum;
    while(high<n-1){
        sum = sum-nums[low];
        low++;
        high++;
        sum = sum+nums[high];
        ans = max(ans,sum);
    }
    return ans/k;
}
};