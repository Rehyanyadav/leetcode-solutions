        if (nums[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (nums[mid] < target)
        // Check if x is present at mid

        int mid = low + (high - low) / 2;
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

