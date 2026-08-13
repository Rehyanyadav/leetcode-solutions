class Solution {
public:
    int addDigits(int num) {

        int result = (num+1)/2;
        result = num*result;
        
        return result;
    }
};
