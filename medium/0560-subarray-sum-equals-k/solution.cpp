class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int > map;
        int currentSum = 0;
        int count = 0;
        map[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            int rem = currentSum - k;

            if (map.find(rem) != map.end()) {
                count += map[rem];
            }

            map[currentSum]++;
        }
        
        return count;
    }
};