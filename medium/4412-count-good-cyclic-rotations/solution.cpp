#include <vector>

class Solution {
public:
    int countGoodRotations(std::vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        

        long long totalSum = computeTotalSum(nums);
        
        long long windowSum = 0;
        for (int i = 0; i < half; ++i) {
            windowSum += nums[i];
        }
        
        int goodCount = 0;
        

        for (int i = 0; i < n; ++i) {
            if (2 * windowSum > totalSum) {
                goodCount++;
            }
            

            windowSum -= nums[i];
            windowSum += nums[(i + half) % n];
        }
        
        return goodCount;
    }

private:

    long long computeTotalSum(const std::vector<int>& nums) {
        long long sum = 0;
        for (int val : nums) {
            sum += val;
        }
        return sum;
    }
};