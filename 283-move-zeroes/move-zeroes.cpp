class Solution {
public:
void moveZeroes(vector<int>& nums) {
        int pointer1 = 0;
        int pointer2 = 1;
        while (pointer2<=nums.size()-1)
        {
            if(nums[pointer1]!=0 && nums[pointer2]!=0){
                pointer1++;
                pointer2++;
                continue;
            }
            else if(nums[pointer1]==0 && nums[pointer2]!=0)
            {
                int a = nums[pointer1];
                nums[pointer1] = nums[pointer2];
                nums[pointer2] = a;
                pointer1++;
            }
            else if(nums[pointer1]!=0 && nums[pointer2]==0){
                pointer1++;
                pointer2++;
                continue;
            }
            else{
                pointer2++;
                continue;
             }
            
            pointer2++;
        }
    }
};