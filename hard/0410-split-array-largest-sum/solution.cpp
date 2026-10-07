class Solution {
private:
   int countSubarrays(vector<int>& nums , int maxSum){
     int subarrays = 1;
     long long currSum = 0;
     for(int i = 0; i<nums.size(); i++){
        if(currSum +nums[i] > maxSum){
            subarrays++;
            currSum = nums[i];

        }else{
            currSum +=nums[i];
        }
     }
     return subarrays;

   }

public:
    int splitArray(vector<int>& nums, int k) {
     int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countSubarrays(nums, mid) <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;  
            }
        }

        return ans;   
    }
};