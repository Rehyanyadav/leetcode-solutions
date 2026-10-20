class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        int maxFreq = 0;
        for (char c : s) {
            freqMap[c]++;
            maxFreq = max(maxFreq, freqMap[c]);
        }
        

        vector<string> buckets(maxFreq + 1, "");
        for (auto& pair : freqMap) {
            char c = pair.first;
            int freq = pair.second;
            buckets[freq].append(freq, c); 
        }

        string result = "";
        for (int i = maxFreq; i > 0; i--) {
            if (!buckets[i].empty()) {
                result += buckets[i];
            }
        }
        
        return result;
    }
};