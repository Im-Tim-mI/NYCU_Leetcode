class Solution {
    public:
        bool isMatch(string s, string p) {
            int m = s.length(), n = p.length();
            vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
            dp[0][0] = true;  // 空字串與空樣式匹配
    
            // 初始化：當 pattern 開頭為星號時，仍可能匹配空字串
            for (int j = 1; j <= n; ++j)
                if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
    
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (p[j - 1] == '*') {
                        // * 匹配 0 或多個
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                        // 單字元相同 or ?
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
    
            return dp[m][n];
        }
    };
    