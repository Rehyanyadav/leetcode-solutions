class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        for(int i =0; i<nums.size(); i++){
            // comparing element to the next element 
        }
            (cicular way)
            if(nums[i]> nums[(i+1) % n] ){
                drops++;
            }
    }

        return drops<=1;

};
