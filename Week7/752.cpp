class Solution {
    public:
        int openLock(vector<string>& deadends, string target) {
            unordered_set<string> dead(deadends.begin(), deadends.end());
            if (dead.count("0000")) return -1;
            if (target == "0000") return 0;
    
            queue<string> q;
            unordered_set<string> visited;
            q.push("0000");
            visited.insert("0000");
    
            int steps = 0;
            while (!q.empty()) {
                int sz = q.size();
                ++steps;
                for (int i = 0; i < sz; ++i) {
                    string curr = q.front(); q.pop();
                    for (string next : getNext(curr)) {
                        if (dead.count(next) || visited.count(next)) continue;
                        if (next == target) return steps;
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            return -1;
        }
    
    private:
        vector<string> getNext(string s) {
            vector<string> res;
            for (int i = 0; i < 4; ++i) {
                char c = s[i];
                s[i] = (c == '9') ? '0' : c + 1;
                res.push_back(s);
                s[i] = (c == '0') ? '9' : c - 1;
                res.push_back(s);
                s[i] = c;
            }
            return res;
        }
    };
    