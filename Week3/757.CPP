class Solution {
    public:
        int intersectionSizeTwo(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
            });
    
            int ans = 0, first = -1, second = -1;
    
            for (auto& interval : intervals) {
                int start = interval[0], end = interval[1];
    
                bool firstIn = (start <= first);
                bool secondIn = (start <= second);
    
                if (firstIn && secondIn) continue;
    
                if (firstIn) {
                    ++ans;
                    second = first;
                    first = end;
                } else {
                    ans += 2;
                    second = end - 1;
                    first = end;
                }
            }
    
            return ans;
        }
    };
    