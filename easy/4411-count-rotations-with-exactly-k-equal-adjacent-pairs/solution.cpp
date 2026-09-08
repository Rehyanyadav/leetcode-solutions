class Solution {
public:
    int countRotations(string s, int k) {
       int n = s.length();
        int c = 0;

        // Count equal adjacent pairs in the circular string
        for (int i = 0; i < n; ++i) {
            if (s[i] == s[(i + 1) % n]) {
                c++;
            }
        }

        // Check against target score k
        if (k == c) {
            return n - c;
        } else if (k == c - 1) {
            return c;
        }
        
        return 0; 
    }
};