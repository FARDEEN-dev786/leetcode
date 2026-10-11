class Solution {
public:
    
int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int low = 0;
    int high = 0;
    unordered_map<char, int> mpp;

    while (high < s.size()) {
        if (mpp.find(s[high]) != mpp.end()) {
            mpp.erase(s[low]);
            low++;
        }
        else {
            mpp[s[high]]++;
            ans = max(ans, high - low + 1);
            high++;
        }
    }

    return ans;
}

};