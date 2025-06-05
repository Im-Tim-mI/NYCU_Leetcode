class Solution {
public:
    string removeDuplicates(string s, int k) {
        struct Node { char ch; int cnt; };
        vector<Node> st;

        for (char c : s) {
            if (!st.empty() && st.back().ch == c) {
                if (++st.back().cnt == k) st.pop_back();  // 滿 k 刪除
            } else {
                st.push_back({c, 1});
            }
        }
        string res;
        for (auto &node : st) res.append(node.cnt, node.ch);
        return res;
    }
};
