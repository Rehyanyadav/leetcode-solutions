class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
        int i = n-1;
        while(i>=0){
            while( i>= 0 && s[i]== ' '){
                i--;
            }
            if(i<0) break;
            int j = i;
            while(i>=0 && s[i] != ' '){
                i--;
            }
            string sub = s.substr(i+1 , j-i);
            if(result.length() == 0){
                result = sub;
            }else{
                result += " "+sub;
            }

        }

        return result;


    }
};