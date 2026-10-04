class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1; // Search right
            } 
            // If right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1; // Search left
            }
        }
        
        return ans;
    }
};