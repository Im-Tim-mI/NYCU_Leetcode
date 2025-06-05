class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<long long> f(k + 1, 0);   // f[j] = f(j, m)
        int m = 0;
        while (f[k] < n) {
            ++m;
            for (int j = k; j >= 1; --j)
                f[j] = f[j] + f[j - 1] + 1;
        }
        return m;
    }
};
