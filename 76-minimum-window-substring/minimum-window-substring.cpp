class Solution {
public:
    string minWindow(string s, string t){
    if(t.size()> s.size()){
        return "";
    }
    int low = 0;
    int high = 0;
    vector<int> mpp_t(256);
    vector<int> mpp_s(256);
    int k = t.size();
    int n = s.size();
    int start = 0;
    int res = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        mpp_t[t[i]]++;
    }
    for (int high = 0; high < n; high++)
    {
        mpp_s[s[high]]++;

        while (s_contain_t(mpp_s,mpp_t))
        {
            int len = high - low+1;
            if(len<res){
                res = len;
                start = low;
            }
            mpp_s[s[low]]--;
            low++;  
        }
    }
    if(res != INT_MAX){
        return s.substr(start,res);
    }
    
    return "";

    
}

bool s_contain_t(vector<int>&s,vector<int>&t){
    for (int i = 0; i<t.size(); i++)
    {
        if(s[i]<t[i]){
            return false;
        }
    }
    return true;
}
};