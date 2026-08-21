class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = -1;
        while(low <= high){
            long long mid = low+(high-low)/2;
            long long msq = mid * mid;
            if(msq == x){
                return mid;
            }
            else if(msq <x){
                ans = mid;
                low = mid+1;

            }
            else{
                high = mid-1;
            }

        }

        
        return ans;

    }
};