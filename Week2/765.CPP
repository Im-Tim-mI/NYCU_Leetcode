class Solution {
    public:
        int minSwapsCouples(vector<int>& row) {
            int n = row.size() / 2;
            vector<int> parent(n);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
    
            function<int(int)> find = [&](int x) {
                if (parent[x] != x)
                    parent[x] = find(parent[x]);
                return parent[x];
            };
    
            auto unite = [&](int x, int y) {
                parent[find(x)] = find(y);
            };
    
            for (int i = 0; i < row.size(); i += 2) {
                int a = row[i] / 2;
                int b = row[i + 1] / 2;
                unite(a, b);
            }
    
            int groups = 0;
            for (int i = 0; i < n; ++i)
                if (parent[i] == i) ++groups;
    
            return n - groups;
        }
    };
    