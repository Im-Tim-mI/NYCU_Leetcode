class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.empty()) return nullptr;
            return mergeRange(lists, 0, lists.size() - 1);
        }
    
    private:
        ListNode* mergeRange(vector<ListNode*>& lists, int l, int r) {
            if (l == r) return lists[l];
            int mid = l + (r - l) / 2;
            ListNode* left = mergeRange(lists, l, mid);
            ListNode* right = mergeRange(lists, mid + 1, r);
            return mergeTwoLists(left, right);
        }
    
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode dummy(0);
            ListNode* curr = &dummy;
    
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    curr->next = l1;
                    l1 = l1->next;
                } else {
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            }
    
            curr->next = l1 ? l1 : l2;
            return dummy.next;
        }
    };
    