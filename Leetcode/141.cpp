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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

// let's say 2 people are running in a circular track
// one person is running slowly and another person is running faster(2 times the speed of first person)

// After a certain period of time person 2 again meet or overtake person 1,
// In that case we can conclude that the track is circular ( replace running track with our Linked list)
