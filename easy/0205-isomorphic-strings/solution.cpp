class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapS(256, 0);
        vector<int> mapT(256, 0);
        
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            // If mappings exist, check if they match our current characters
            if (mapS[c1] != 0 && mapS[c1] != c2) return false;
            if (mapT[c2] != 0 && mapT[c2] != c1) return false;
            
            // Establish the bidirectional mapping
            mapS[c1] = c2;
            mapT[c2] = c1;
        }
        
        return true;
    }
};