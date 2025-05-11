class Solution {
    public:
        int shortestPathLength(vector<vector<int>>& graph) {
            int n = graph.size();
            if (n == 1) return 0;
    
            queue<pair<int, int>> q;  // {node, visitedMask}
            vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
    
            for (int i = 0; i < n; ++i) {
                int mask = 1 << i;
                q.push({i, mask});
                visited[i][mask] = true;
            }
    
            int steps = 0;
            while (!q.empty()) {
                int sz = q.size();
                while (sz--) {
                    auto [node, mask] = q.front(); q.pop();
    
                    if (mask == (1 << n) - 1)
                        return steps;
    
                    for (int neighbor : graph[node]) {
                        int nextMask = mask | (1 << neighbor);
                        if (!visited[neighbor][nextMask]) {
                            visited[neighbor][nextMask] = true;
                            q.push({neighbor, nextMask});
                        }
                    }
                }
                ++steps;
            }
    
            return -1;  // 理論上不會進到這裡
        }
    };
    