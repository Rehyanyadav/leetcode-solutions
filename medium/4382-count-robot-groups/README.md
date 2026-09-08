# Q3. Count Robot Groups

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a strictly increasing integer array position, where position[i] is the initial position of the ith robot at time t = 0.

You are also given an integer array speed, where speed[i] is the constant speed of the ith robot in units per second, and an integer distance.

Time is continuous and measured in seconds. A robot or group with speed v moves v * t units to the right over any interval of t seconds.

Whenever the distance between two robots or groups becomes at most distance, they merge into a single group.

If multiple robots or groups satisfy the merging condition at the same time, all merges happen simultaneously. In particular, every connected collection of robots or groups whose consecutive positions differ by at most distance merges into one group.

After a merge, the resulting group takes the current position and speed of the rightmost robot in that group. Once merged, robots never separate.

Return the number of groups remaining after all possible merges have occurred.

 
Example 1:


Input: position = [1,5,6,20], speed = [4,3,2,3], distance = 1

Output: 2

Explanation:




	Initially, the groups are {R1}, {R2}, {R3}, and {R​​​​​​​4}.
	At t = 0, the robots R2 and R3 at positions 5 and 6, respectively, merge because they are 1 unit apart. The resulting group moves with the position and speed of the rightmost robot R3. The groups are now {R1}, {R2, R3}, and {R​4}.
	Later at t = 2, the robot R1 catches up to the group {R2, R3} and merges with it. The groups are now {R1, R2, R3} and {R​4}.


Thus, the answer is 2.


Example 2:


Input: position = [1,5,9], speed = [3,2,2], distance = 2

Output: 2

Explanation:




	Initially, the groups are {R1}, {R2}, and {R3}.
	At t = 2, the robot R1 catches up to the robot R2 and merges with it. The resulting group moves with the position and speed of the rightmost robot R2. The groups are now {R1, R2} and {R3}.


Thus, the answer is 2.


Example 3:


Input: position = [9], speed = [8], distance = 5

Output: 1

Explanation:

Initially, there is only one group. Therefore, the answer is 1.


 
Constraints:


	1 <= position.length == speed.length <= 105
	1 <= position[i], speed[i], distance <= 109
	position is strictly increasing.

## Solution

**Language:** C++  
**Runtime:** 19 ms (beats 23.89%)  
**Memory:** 228.9 MB (beats 11.66%)  
**Submitted:** 2026-09-08T02:46:30.495Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/count-robot-groups/)