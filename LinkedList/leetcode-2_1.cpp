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
    // addLast takes a linked list & a single ListNode, appends this ListNode
    // at the end of the list & returns the head of the new linked list
    ListNode* addLast(ListNode *head, ListNode *cur) {
      if (head == nullptr) {
        return cur;
      }

      ListNode *temp = head;
      while (temp -> next != nullptr) {
        temp = temp -> next;
      }
      temp -> next = new ListNode(cur -> val, nullptr);
      return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        assert(l1 != nullptr && l2 != nullptr);
        
        int carry = 0;
        ListNode *ans = nullptr;
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int add = 0;
            if (l1 != nullptr) {
                add += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != nullptr) {
                add += l2 -> val;
                l2 = l2 -> next;
            }
            if (carry > 0) {
                add += carry;
            }
                        
            ans = addLast(ans, new ListNode(add % 10));
            carry = add / 10;
        }
                
        return ans;
    }
};
