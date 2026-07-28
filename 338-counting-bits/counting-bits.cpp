class Solution {
public:
    vector<int> countBits(int n) {
    vector<int>ans(n+1);
    for(int i = 0; i<=n;i++){
        int res = 0;
        int x = i;
        while (x>0)
        {
            res++;
            x = (x-1)&x;
        }
        ans[i] = res;
    }    
    return ans;
}
};