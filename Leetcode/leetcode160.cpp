/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode *head) {
        ListNode *temp = head;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp -> next;
        }
        return length;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = findLength(headA), lenB = findLength(headB);
        
        if (lenA > lenB) {
            int bad = lenA - lenB;
            while (bad--) {
                if (headA == NULL) {
                    return NULL;
                }
                headA = headA -> next;
            }
            while (headA != NULL && headB != NULL) {
                if (headA == headB) {
                    return headA;
                }
                headA = headA -> next;
                headB = headB -> next;
            }
            return NULL;
        } else if (lenA < lenB) {
            int bad = lenB - lenA;
            while (bad--) {
                if (headB == NULL) {
                    return NULL;
                }
                headB = headB -> next;
            }
            while (headA != NULL && headB != NULL) {
                if (headA == headB) {
                    return headA;
                }
                headA = headA -> next;
                headB = headB -> next;
            }
            return NULL;
        } else {
            while (headA != NULL && headB != NULL) {
                if (headA == headB) {
                    return headA;
                }
                headA = headA -> next;
                headB = headB -> next;
            }
            return NULL;
        }
        return NULL;
    }
};
