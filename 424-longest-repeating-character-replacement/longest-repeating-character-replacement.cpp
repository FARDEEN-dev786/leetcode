class Solution {
public:
    int characterReplacement(string s, int k){
    int low=0;
    int high  =0;
    int res = INT_MIN;
    int n = s.size();
    vector<int>f(256);
    for(high=0;high<n;high++){
        f[s[high]]++;
        int len = high - low+1;
        int maxcnt= maxi(f);
        int diff = len - maxcnt;
        while (diff>k)
        {
            f[s[low]]--;
            low++;
            maxcnt = maxi(f);
            len = high - low +1;
            diff = len - maxcnt;
        }
        len = high-low+1;
        res = max(res,len);
    }
    return res;
}

int maxi(vector<int>&f){
    int maxim = 0;
    for (int i = 0; i < f.size(); i++)
    {
        maxim = max(maxim,f[i]);
    }
    return maxim;
}
};