
class Solution {
private:
    int expandAroundCenter(const string& s, int left, int right) {
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int start = 0, maxLength = 1;

        for (int i = 0; i < n; i++) {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);

            int len = max(odd, even);

            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
