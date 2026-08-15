class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
     //* using two pointer approach 

    /*
    first we initialize 
    two pointers  left and & right 

    */
    int left = 0;
    int right = numbers.size()-1;
 while(numbers[left] +numbers[right] !=target){
    if(numbers[left] + numbers[right] <target){
        ++left;
    }
    else{
        --right;

    }

 }
    }
};