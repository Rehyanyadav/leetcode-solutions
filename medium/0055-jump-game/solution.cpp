class Solution {
public:
    bool canJump(vector<int>& nums) {
//  here  we have to  keep the maximum index we have reach
int max_Reach =0;


// loop till end to the size of array 

for(int i =0; i<nums.size(); i++){
    //here we check  our current i is excced more than max_Reach
    if(i >max_Reach){
        // then we will return false
        return false;

    }

// now here we will  check  how much farthest jump we are geeting  and set it 
max_Reach = max(max_Reach , i+ nums[i]);

}


return true;
    }
};
