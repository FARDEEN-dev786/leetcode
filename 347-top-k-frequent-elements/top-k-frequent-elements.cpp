class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k){
    unordered_map<int,int> mpp;
    for(int i =0;i<nums.size();i++){
        mpp[nums[i]]++;
    }
    vector<int> ans;
    for(int i=0;i<k;i++){
        int maxitem= 0;
        int maxfreq = 0;
        for(auto x:mpp){
            if(x.second>=maxfreq){
                maxfreq =x.second;
                maxitem = x.first;
            }
        }
        ans.push_back(maxitem);
        mpp.erase(maxitem);
    }
    return ans;
}
};