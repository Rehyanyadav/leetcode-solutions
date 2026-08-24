#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // Track the indices (positions) instead of characters
        stack<int> openSt;
        stack<int> starSt;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                openSt.push(i); // Store the index of '('
            } 
            else if (ch == '*') {
                starSt.push(i); // Store the index of '*'
            } 
            else { // Current character is ')'
                // First, try to match with a real opening bracket
                if (!openSt.empty()) {
                    openSt.pop();
                } 
                // If no '(' is available, try to use a '*' as an opening bracket
                else if (!starSt.empty()) {
                    starSt.pop();
                } 
                // If neither is available, it's invalid
                else {
                    return false;
                }
            }
        }

        // After the loop, match remaining '(' with '*' that appear AFTER them
        while (!openSt.empty() && !starSt.empty()) {
            // If the '(' appears AFTER the '*', the '*' cannot balance it (e.g., "*( ")
            if (openSt.top() > starSt.top()) {
                return false;
            }
            openSt.pop();
            starSt.pop();
        }

        // If openSt is empty, all open brackets found a match!
        return openSt.empty();
    }
};
