class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            if (amount == 0) return 0;
    
            vector<bool> visited(amount + 1, false);
            queue<int> q;
            q.push(0);
            visited[0] = true;
    
            int steps = 0;
            while (!q.empty()) {
                int sz = q.size();
                ++steps;
                for (int i = 0; i < sz; ++i) {
                    int curr = q.front(); q.pop();
                    for (int coin : coins) {
                        int next = curr + coin;
                        if (next == amount) return steps;
                        if (next < amount && !visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                }
            }
    
            return -1;
        }
    };
    