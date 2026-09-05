class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxi = max(maxi, count); // Is my current streak a new record?
            } else {
                count = 0; // Streak broken, reset to 0
            }
        }
        
        return maxi;
    }
};