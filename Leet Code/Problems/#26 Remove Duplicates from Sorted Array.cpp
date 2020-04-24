//26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        int current = nums[0];
        int counter = 1;
        for(int i=1;i<nums.size();i++){
            if(current == nums[i]){
                continue;
            }else{
                nums[counter] = nums[i];
                current = nums[i];
                counter++;
            }
        }
        return counter;
    }
};