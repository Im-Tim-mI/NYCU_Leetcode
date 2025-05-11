class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int> candies(n, 1);
    
            // 從左到右：比左邊大就 +1
            for (int i = 1; i < n; ++i) {
                if (ratings[i] > ratings[i - 1])
                    candies[i] = candies[i - 1] + 1;
            }
    
            // 從右到左：比右邊大要至少比右邊多
            for (int i = n - 2; i >= 0; --i) {
                if (ratings[i] > ratings[i + 1])
                    candies[i] = max(candies[i], candies[i + 1] + 1);
            }
    
            return accumulate(candies.begin(), candies.end(), 0);
        }
    };
    