class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int el1 = -1, el2 = -1;
        

        for (int i = 0; i < n; i++) {
            if (count1 == 0 && nums[i] != el2) {
                el1 = nums[i];
                count1 = 1;
            } else if (count2 == 0 && nums[i] != el1) {
                el2 = nums[i];
                count2 = 1;
            } else if (nums[i] == el1) {
                count1++;
            } else if (nums[i] == el2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        int actual_count1 = 0, actual_count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) actual_count1++;
            else if (nums[i] == el2) actual_count2++;
        }
        
        vector<int> ans;
        int threshold = n / 3;
        if (actual_count1 > threshold) ans.push_back(el1);
        if (actual_count2 > threshold) ans.push_back(el2);
        
        return ans;
    }
};