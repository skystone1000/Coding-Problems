// Company Amazon
// 08 #0027 Remove Element
// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i:nums){
            if(i != val){
                nums[count] = i;
                count++;
            }
        }
        return count;
        
        
        // Method 2 (Wrong Answer)
        /*
        int end = nums.size() - 1;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(i+count == nums.size()) break;
            if(nums[i] == val){
                swap(nums[i],nums[end]);
                end--;
                count++;
                i--;
            }
        }
        return count;
        */
    }
};