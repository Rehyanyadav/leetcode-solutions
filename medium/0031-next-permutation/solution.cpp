class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        
        // Step 1: Find the break-point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        
        // If no break-point exists, reverse the entire array
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 2: Find the next greater element and swap
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        
        // Step 3: Reverse the right half
        reverse(nums.begin() + ind + 1, nums.end());
    }
};