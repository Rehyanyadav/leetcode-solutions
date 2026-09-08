# Q4. Minimum Cost Path With At Most K Turns

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 2D integer array grid of size m x n, where grid[i][j] represents the cost of visiting cell (i, j), and an integer k.

You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).

From each cell, you may move one step in any of the four directions: up, down, left, or right.

The cost of a path is the sum of the values of all visited cells, including the starting and ending cells. If a cell is visited more than once, its value is included each time it is visited.

Return the minimum possible path cost to reach (m - 1, n - 1) using at most k turns. If no such path exists, return -1.

A turn occurs when the direction changes between two consecutive moves. For example, moving right and then down counts as one turn, while moving right and then right does not.

 
Example 1:


Input: grid = [[2,7,3],[1,4,5]], k = 1

Output: 12

Explanation:


	An optimal path is (0, 0) → (1, 0) → (1, 1) → (1, 2). The moves are down, right, right.
	The direction changes from down to right once, so the path uses exactly k = 1 turn.
	The total path cost is 2 + 1 + 4 + 5 = 12.



Example 2:


Input: grid = [[4,1,9],[3,2,5],[4,8,6]], k = 2

Output: 20

Explanation:​​​​​​​


	An optimal path is (0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2). The moves are down, right, right, down.
	The direction changes from down to right and from right to down, so the path uses exactly k = 2 turns.
	The total path cost is 4 + 3 + 2 + 5 + 6 = 20.



Example 3:


Input: grid = [[1,9],[3,4]], k = 0

Output: -1

Explanation:


	It is impossible to reach (1, 1) using k = 0 turns. Thus, the answer is -1.



 
Constraints:


	1 <= m == grid.length <= 75
	1 <= n == grid[i].length <= 75
	0 <= grid[i][j] <= 1000
	0 <= k < min(m, n)

## Solution

**Language:** C++  
**Runtime:** 552 ms (beats 52.42%)  
**Memory:** 116.5 MB (beats 37.79%)  
**Submitted:** 2026-09-08T02:48:34.773Z  

```cpp
#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions: 0: Up, 1: Right, 2: Down, 3: Left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // dist[r][c][dir][turns]
        // dir: 0 to 3, with 4 representing the initial state (no previous move)
        const long long INF = 1e18;
        std::vector<std::vector<std::vector<std::vector<long long>>>> dist(
            m, std::vector<std::vector<std::vector<long long>>>(
                n, std::vector<std::vector<long long>>(5, std::vector<long long>(k + 1, INF))
            )
        );
        
        // Priority queue stores: {cost, r, c, dir, turns}
        using State = std::tuple<long long, int, int, int, int>;
        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
        
        // Start state: r = 0, c = 0, dir = 4 (none), turns = 0, cost = grid[0][0]
        pq.push({grid[0][0], 0, 0, 4, 0});
        dist[0][0][4][0] = grid[0][0];
        
        while (!pq.empty()) {
            auto [cost, r, c, dir, turns] = pq.top();
            pq.pop();
            
            // Reached the destination
            if (r == m - 1 && c == n - 1) {
                return cost;
            }
            
            if (cost > dist[r][c][dir][turns]) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                
                int next_turns = turns;
                // If a previous move exists and the direction changes, it counts as a turn
                if (dir != 4 && dir != i) {
                    next_turns++;
                }
                
                if (next_turns > k) continue;
                
                long long next_cost = cost + grid[nr][nc];
                if (next_cost < dist[nr][nc][i][next_turns]) {
                    dist[nr][nc][i][next_turns] = next_cost;
                    pq.push({next_cost, nr, nc, i, next_turns});
                }
            }
        }
        
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-cost-path-with-at-most-k-turns/)