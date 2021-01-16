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
    int getLength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head -> next;
        }
        return length;
    }
    
    ListNode* middleNode(ListNode* head) {
        int length = getLength(head);
        int middle = length / 2;
        
        while (middle--) {
            head = head -> next;
        }
        
        return head;
    }
};
