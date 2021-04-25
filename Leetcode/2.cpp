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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Temp = new ListNode(0);
        ListNode* Head = Temp;
        
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            if (carry) {
                sum += carry;
            }
                        
            Temp -> next = new ListNode(sum % 10);
            carry = sum / 10;
            Temp = Temp -> next;
        }
        
        return Head -> next;
    }
};
