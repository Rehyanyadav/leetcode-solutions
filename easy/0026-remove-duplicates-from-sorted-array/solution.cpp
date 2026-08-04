class Solution {
public:

int solve(vector<int> & nums){
    int n  = nums.size();
    if(n == 0 ){
        return 0;
    }
    int i =0; int j = 0;
    while( j <n){
         if(nums[i] != nums[j]){
            i++;
            nums[i] = nums[j];

         }
         j++;

    }
    return i+1;

}
    int removeDuplicates(vector<int>& nums) {
     return solve(nums);
         
    }
};