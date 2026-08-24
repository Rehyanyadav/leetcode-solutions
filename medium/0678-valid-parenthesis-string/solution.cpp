class Solution {
public:
    bool checkValidString(string s) {
         int min_val = 0; // Tracks the minimum possible open brackets '('
        int max_val = 0; // Tracks the maximum possible open brackets '('

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                min_val++;
                max_val++;
            } 
            else if (s[i] == ')') {
                min_val--;
                max_val--;
            } 
            else { // It is an asterisk '*'
                min_val--; // If '*' acts as ')'
                max_val++; // If '*' acts as '('
            }

            // At any point, if max_val drops below 0, there are too many 
            closing brackets
            if (max_val < 0) {
                return false;
            }

            // min_val cannot be negative; reset it to 0 (assume '*' acts as 
