class Solution {
private:
    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int n = nums.size();
        int l = 0, totalCount = 0;
        unordered_map<int, int> freqMap;
        
        for (int r = 0; r < n; r++) {
            if (freqMap[nums[r]] == 0) {
                k--; 
            }
            freqMap[nums[r]]++;
            while (k < 0) {
                freqMap[nums[l]]--;
                if (freqMap[nums[l]] == 0) {
                    k++; 
                }
                l++;
            }

            totalCount += (r - l + 1);
        }
        
        return totalCount;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};