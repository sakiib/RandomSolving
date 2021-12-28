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
    
    // length takes the head of a linked list & returns it's length
    int length(ListNode *head) {
      ListNode *temp = head;
      int len = 0;
      while (temp != nullptr) {
        len++;
        temp = temp -> next;
      }
      return len;
    }
    
    // reverseList takes a linked list, reverses it and returns the new head
    ListNode* reverseList(ListNode *head) {
      ListNode *dummy = nullptr;
      while (head != nullptr) {
        ListNode* next = head -> next;
        head -> next = dummy;
        dummy = head;
        head = next;
      }
      return dummy;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        
        assert(len1 > 0 && len2 > 0);
        
        if (len1 < len2) {
            for (int i = 1; i <= len2 - len1; i++) {
                l1 = addLast(l1, new ListNode(0));
            }
        }
        if (len2 < len1) {
            for (int i = 1; i <= len1 - len2; i++) {
                l2 = addLast(l2, new ListNode(0));
            }
        }
        
        ListNode *ans = nullptr;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *cur = new ListNode((l1 -> val + l2 -> val + carry) % 10);
            carry = (l1 -> val + l2 -> val + carry) / 10;
            ans = addLast(ans, cur);
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        if (carry) {
            ans = addLast(ans, new ListNode(carry));
        }
                
        return ans;
    }
};
