/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *temp = cur -> next;
            while (temp != nullptr && temp -> val == cur -> val) {
                temp = temp -> next;
            }
            cur -> next = temp;
            cur = cur -> next;
        }
        return head;
    }
};
