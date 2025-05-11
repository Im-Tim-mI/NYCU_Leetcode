class Solution {
    public:
        int paintWalls(vector<int>& cost, vector<int>& time) {
            int n = cost.size();
            // 最多需要塗 n 面牆，最多也只需 n 時間給免費工人
            const int INF = 1e9;
            vector<int> dp(n + 1, INF);  // dp[i] = 最少花費，讓免費工人能塗 i 面牆
            dp[0] = 0;  // 不給免費工人任何時間，花費 0（初始）
    
            for (int i = 0; i < n; ++i) {
                // 逆序更新，確保不重複選同一面牆
                for (int j = n; j >= 0; --j) {
                    int nextTime = min(n, j + time[i] + 1);  // 加上這次可併行時間（本牆1時間 + 免費工人併行 time[i]）
                    dp[nextTime] = min(dp[nextTime], dp[j] + cost[i]);
                }
            }
    
            return dp[n];  // 讓免費工人塗滿 n 面牆所需最小花費
        }
    };
    