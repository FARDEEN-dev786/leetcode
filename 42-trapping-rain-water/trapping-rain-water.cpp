class Solution {
public:
    int trap(vector<int>& height){
    int water =0;
    int n = height.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    prefix[0]=height[0];
    suffix[n-1]=height[n-1];
    for (int i = 1; i < n; i++)
    {
        prefix[i]=max(prefix[i-1],height[i]);
    }
    for (int i = n-2; i>=1; i--)
    {
        suffix[i]=max(suffix[i+1],height[i]);
    }
    for (int i = 1; i < n-1; i++)
    {
        int newdrop = min(prefix[i],suffix[i])-height[i];
        if(newdrop>0){
            water += newdrop;
        }
    }
    return water;  
}
};