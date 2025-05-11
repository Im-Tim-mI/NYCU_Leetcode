class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            if (intervals.empty()) return 0;
    
            sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
                return a[1] < b[1];  // 按結束時間排序
            });
    
            int end = intervals[0][1];
            int count = 1;
    
            for (int i = 1; i < intervals.size(); ++i) {
                if (intervals[i][0] >= end) {
                    ++count;
                    end = intervals[i][1];
                }
            }
    
            return intervals.size() - count;  // 刪除區間數 = 全部 - 不重疊區間數
        }
    };
    