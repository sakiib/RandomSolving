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
    // middle of the linked-list using only one-pass
    ListNode* middleNode(ListNode* head) {
        ListNode* second = head;
        ListNode* first = head;
        while (second != nullptr) {
            second = second -> next;
            if (second != nullptr) {
                second = second -> next;
            } else {
                break;
            }
            first = first -> next;
        }
        return first;
    }
};
