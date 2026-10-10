class Solution {
public:
    int maxArea(vector<int>& height){
    int max_water =0;
    int left =0;
    int right = height.size()-1;
    while(left<right){
        int width = right-left;
        int unchai = min(height[right],height[left]);
        int area = width*unchai;
        max_water = max(max_water,area);
        if(height[right]<height[left]){
            right--;
        }
        else{
            left++;
        }
    }
    return max_water;
}
};