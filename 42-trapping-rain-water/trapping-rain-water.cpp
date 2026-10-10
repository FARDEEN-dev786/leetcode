class Solution {
public:
    int trap(vector<int>& height){
    int water =0;
    int n = height.size();
    int leftmax=height[0];
    vector<int> suffix(n);
    
    suffix[n-1]=height[n-1];
    for (int i = n-2; i>=1; i--)
    {
        suffix[i]=max(suffix[i+1],height[i]);
    }
    for (int i = 1; i < n-1; i++)
    {
        if(height[i-1]>leftmax){
            leftmax = height[i-1];
        }
        int newdrop = min(leftmax,suffix[i])-height[i];
        if(newdrop>0){
            water += newdrop;
        }
    }
    return water;  
}
};