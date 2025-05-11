class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (!head || !head->next) return head;
    
            ListNode* first = head;
            ListNode* second = head->next;
    
            first->next = swapPairs(second->next);  // 遞迴處理後續
            second->next = first;
    
            return second;  // 新的頭節點
        }
    };
    