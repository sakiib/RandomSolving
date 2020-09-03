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
    ListNode* head;
    void addLast(int v) {
        ListNode* temp = head;
        while (temp -> next != NULL) temp = temp -> next;
        ListNode* now = new ListNode(v);
        temp -> next = now;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        head = new ListNode();
        while (l1 != NULL && l2 != NULL) {
            if (head == NULL) {
                if (l1 -> val <= l2 -> val) {
                    head = l1;
                    l1 = l1 -> next;
                }
                else {
                    head = l2;
                    l2 = l2 -> next;
                }
            }
            else {
                if (l1 -> val <= l2 -> val) {
                    addLast(l1 -> val);
                    l1 = l1 -> next;
                }
                else {
                    addLast(l2 -> val);
                    l2 = l2 -> next;
                }
            }
        }
        while (l1 != NULL) addLast(l1 -> val), l1 = l1 -> next;
        while (l2 != NULL) addLast(l2 -> val), l2 = l2 -> next;
        return head -> next;
    }
};
