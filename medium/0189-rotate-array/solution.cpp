class Solution {
public:
    void rotate(vector<int>& nums, int k) {
int temp[k];
    temp[i] = nums[i];
 
     }
  for(int i =0; i<k; i++)
    for(int i =k; i<nums.size(); i++)
       nums[i-k] = nums[i];
    for(int i = 0; i<k; i++)
        nums[nums.size() - k +i] = temp[i];

};
