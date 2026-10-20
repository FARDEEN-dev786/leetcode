class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    int res = 0;
    unordered_map<int,int> f;
    for(int i =0; i<n;i++){
        sum += nums[i];
        int rem = sum%k;
        if(rem==0){
            res = max(res,i+1);
        }
        if(rem<0) rem = rem+k;
        if(f.find(rem)==f.end()){
            f[rem] = i;
        }
        else{
            int length =i-f[rem];
            res = max(res,length);
        }
    }
    if(res>=2){
        return true;
    }
    return false;
}
};