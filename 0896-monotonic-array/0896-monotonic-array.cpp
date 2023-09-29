class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
         bool increase = false;
         bool decrease = false;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                decrease = true;
            }
            if (nums[i] > nums[i - 1]) {
                increase = true;
            }
        }
        
        return increase && decrease ? false : true;
    }
};