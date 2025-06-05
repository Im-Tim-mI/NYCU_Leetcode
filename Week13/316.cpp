class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int N = s.size();
        array<int, 26> last{};
        for (int i = 0; i < N; ++i)
            last[s[i] - 'a'] = i;

        array<bool, 26> inStack{};
        string stack;
        stack.reserve(26);

        for (int i = 0; i < N; ++i) {
            char c = s[i];
            int idx = c - 'a';
            if (inStack[idx]) continue;

            while (!stack.empty() &&
                   c < stack.back() &&
                   last[stack.back() - 'a'] > i) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(c);
            inStack[idx] = true;
        }
        return stack;
    }
};
