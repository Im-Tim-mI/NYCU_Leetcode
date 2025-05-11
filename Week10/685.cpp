class Solution {
    public:
        vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            vector<int> parent(n + 1);
            iota(parent.begin(), parent.end(), 0);
    
            vector<int> cand1, cand2;
            vector<int> nodeParent(n + 1, 0);
    
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                if (nodeParent[v] == 0)
                    nodeParent[v] = u;
                else {
                    cand1 = {nodeParent[v], v}; // 第一條指向 v 的邊
                    cand2 = edge;               // 第二條指向 v 的邊
                    edge[1] = 0; // 標記此邊無效（先不處理）
                }
            }
    
            // Union-Find 判斷是否成環
            iota(parent.begin(), parent.end(), 0);
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                if (v == 0) continue; // 跳過被標記移除的邊
                int pu = find(parent, u);
                if (pu == v) {
                    return cand1.empty() ? edge : cand1; // 若無雙父則回傳當前形成環的邊；否則回 cand1
                }
                parent[v] = pu;
            }
    
            return cand2; // 若無成環，回傳 cand2（合法回退）
        }
    
    private:
        int find(vector<int>& parent, int x) {
            return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
        }
    };
    