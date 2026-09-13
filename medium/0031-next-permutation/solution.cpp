        }
        
        if (ind == -1) {
        // If no break-point exists, reverse the 
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 2: Find the next greater element and 
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
        entire array
        swap
            }
        }
        
        // Step 3: Reverse the right half
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
