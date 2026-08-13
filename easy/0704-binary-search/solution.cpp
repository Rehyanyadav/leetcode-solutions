class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
/*

we can use both 
int mid = ( low + high ) /2;
int mid = low+( high-low )/2;

second version is generally preffered because it avoids integers overflow

*/
        int mid = low + (high - low) / 2;
          
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
    }
};