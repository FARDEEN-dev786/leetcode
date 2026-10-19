class NumArray {
    vector<int> pref;
public:
    NumArray(vector<int>& nums) {
        pref.resize(nums.size());
        pref[0] = nums[0];
        for(int i =1;i<nums.size();i++){
            pref[i] = pref[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            int ans = pref[right];
            return ans;
        }
        int ans = pref[right]-pref[left-1];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */