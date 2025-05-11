class Solution {
    public:
        vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
            vector<vector<int>> tree(n);
            for (auto& e : edges) {
                tree[e[0]].push_back(e[1]);
                tree[e[1]].push_back(e[0]);
            }
    
            vector<int> count(n, 1);     // 子樹節點數
            vector<int> answer(n, 0);    // 距離總和
    
            // 第一次 DFS：計算每個節點的子樹大小和距離和
            dfs(0, -1, tree, count, answer);
    
            // 第二次 DFS：重新計算其他節點的距離
            dfs2(0, -1, tree, count, answer, n);
    
            return answer;
        }
    
    private:
        void dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& count, vector<int>& answer) {
            for (int child : tree[node]) {
                if (child == parent) continue;
                dfs(child, node, tree, count, answer);
                count[node] += count[child];
                answer[node] += answer[child] + count[child];
            }
        }
    
        void dfs2(int node, int parent, vector<vector<int>>& tree, vector<int>& count, vector<int>& answer, int n) {
            for (int child : tree[node]) {
                if (child == parent) continue;
                answer[child] = answer[node] - count[child] + (n - count[child]);
                dfs2(child, node, tree, count, answer, n);
            }
        }
    };
    