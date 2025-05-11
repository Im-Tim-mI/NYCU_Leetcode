#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // 存索引
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // 移除超出視窗左邊的索引
            if (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();

            // 維持遞減順序，移除比當前值小的元素索引
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // 視窗形成後開始收集結果
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
