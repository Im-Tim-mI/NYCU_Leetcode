class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            unordered_map<string, vector<string>> memo;
            return dfs(s, dict, memo);
        }
    
    private:
        vector<string> dfs(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
            if (memo.count(s)) return memo[s];
            if (s.empty()) return {""};
    
            vector<string> res;
            for (int i = 1; i <= s.size(); ++i) {
                string prefix = s.substr(0, i);
                if (dict.count(prefix)) {
                    vector<string> subList = dfs(s.substr(i), dict, memo);
                    for (string sub : subList) {
                        res.push_back(prefix + (sub.empty() ? "" : " " + sub));
                    }
                }
            }
    
            memo[s] = res;
            return res;
        }
    };
    