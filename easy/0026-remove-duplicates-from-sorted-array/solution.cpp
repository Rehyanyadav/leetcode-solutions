class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //* here we checked array is empty or not 
        if(nums.empty()) return 0;

        int i =0;  // creating the slow pointer which will be  keep track of the  unique element

     //here we traverse through the array  by using second pointer  
        for( int j =0; j<nums.size(); j++){
            // if  jth element is not equal to ith element 
             if(nums[j]!= nums[i]){
    // increment the i
                i++;

                // and overwrite  the duplicate element with new element
                nums[i] = nums[j];


             }
        }

    // then return the unique element 
         return  (i+1);


    }
};