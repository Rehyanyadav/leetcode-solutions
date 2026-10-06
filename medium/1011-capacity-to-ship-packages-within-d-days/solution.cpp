class Solution {

private:
    int findDays(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > capacity) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (findDays(weights, mid) <= days) {
                ans = mid;
                high = mid - 1; // Try to find a smaller capacity
            } else {
                low = mid + 1;  // Capacity too small, increase it
            }
        }

        return ans;
    }
};