class Solution {
public:
    int countGroups(std::vector<int>& position, std::vector<int>& speed, int distance) {
        int n = position.size();
        

        std::vector<std::pair<long long, long long>> groups;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && position[j + 1] - position[j] <= distance) {
                j++;
            }

            groups.push_back({position[j], speed[j]});
            i = j + 1;
        }
        
        std::vector<std::pair<long long, long long>> stack;
        for (int k = (int)groups.size() - 1; k >= 0; --k) {
            long long curPos = groups[k].first;
            long long curSpeed = groups[k].second;
            

            while (!stack.empty() && curSpeed > stack.back().second) {
                curPos = stack.back().first;
                curSpeed = stack.back().second;
                stack.pop_back();
            }
            stack.push_back({curPos, curSpeed});
        }
        
        return stack.size();
    }
};