class Solution {
public:
    bool canJump(vector<int>& nums) {
//  here  we have to  keep the maximum index we have reach
int max_Reach =0;


// loop till end to the size of array 

for(int i =0; i<nums.size(); i++){
    if(i >max_Reach){
        return false;

    }

max_Reach = max(max_Reach , i+ nums[i]);

}
return true;
    }
};