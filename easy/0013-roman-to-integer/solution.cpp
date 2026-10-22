class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int n = s.length();
        

        auto getValue = [](char c) {
            switch(c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        };
        
        for (int i = n - 1; i >= 0; i--) {
            int currVal = getValue(s[i]);
            

            if (i < n - 1 && currVal < getValue(s[i + 1])) {
                total -= currVal; // Subtract
            } else {
                total += currVal; // Add
            }
        }
        
        return total;
    }
};