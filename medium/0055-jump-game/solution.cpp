class Solution {
public:
    bool canJump(vector<int>& nums) {
int max_Reach =0;
for(int i =0; i<nums.size(); i++){
    if(i >max_Reach){
        return false;
    }
}


    }
max_Reach = max(max_Reach , i+ nums[i]);

return true;
};
