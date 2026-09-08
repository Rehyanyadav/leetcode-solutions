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