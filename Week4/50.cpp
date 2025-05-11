class Solution {
    public:
        double myPow(double x, int n) {
            long long N = n;  // 避免溢位（如 n = INT_MIN）
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
            return powRecursive(x, N);
        }
    
    private:
        double powRecursive(double x, long long n) {
            if (n == 0) return 1.0;
            double half = powRecursive(x, n / 2);
            return (n % 2 == 0) ? half * half : half * half * x;
        }
    };
    