class Solution {
public:

 int charToInt(char c) {
        return c - '0';
    }


    int getBit(const std::string& str, int index) {
        if (index >= 0) {
            return charToInt(str[index]);
        }
        return 0; // Return 0 if we run out of digits on the left
    }
    string addBinary(string a, string b) {
           string result = "";
        

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;


        while (i >= 0 || j >= 0 || carry > 0) {

            int sum = carry + getBit(a, i) + getBit(b, j);


            result += std::to_string(sum % 2);


            carry = sum / 2;


            i--;
            j--;
        }


reverse(result.begin(), result.end());

        return result;
    }
};