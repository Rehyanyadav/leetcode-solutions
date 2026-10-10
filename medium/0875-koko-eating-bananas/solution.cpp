class Solution {

private:
    long long getTotalHours(vector<int>& piles, int speed) {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {

            totalHours += (piles[i] + speed - 1) / speed;
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (getTotalHours(piles, mid) <= h) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }

        return ans;
    }
};