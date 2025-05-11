class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* node = head;
            for (int i = 0; i < k; ++i) {
                if (!node) return head;  // 不足 k 個，不反轉
                node = node->next;
            }
    
            ListNode* newHead = reverse(head, node);
            head->next = reverseKGroup(node, k);  // 遞迴處理下一段
            return newHead;
        }
    
    private:
        ListNode* reverse(ListNode* start, ListNode* end) {
            ListNode* prev = nullptr;
            ListNode* curr = start;
            while (curr != end) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            return prev;
        }
    };
    