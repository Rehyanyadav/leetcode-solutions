class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int cnt = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                cnt--; 
            }
            
            if (cnt > 0) {
                res += s[i]; 
            }
            
            if (s[i] == '(') {
                cnt++; 
            }
        }
        
        return res;
    }
};