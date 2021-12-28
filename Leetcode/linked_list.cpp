#include <bits/stdc++.h>
using namespace std;

// some boring linked list tasks
// definition for singly linked list
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

// printList takes the head of a linked list & prints it
void printList(ListNode *head) {
  ListNode *temp = head;
  cout << "list: ";
  while (temp != nullptr) {
    cout << temp -> val;
    temp = temp -> next;
    if (temp != nullptr) {
      cout << ", ";
    }
  }
  cout << "\n";
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

// printLength takes the head of a linked list & prints it's length
void printLength(ListNode *head) {
  cout << "list length: " << length(head) << "\n";
}

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

// addFirst takes a linked list & a single ListNode, appends this ListNode
// at the beginning of the list & returns the head of the new linked list
ListNode* addFirst(ListNode *head, ListNode *cur) {
  if (head == nullptr) {
    return cur;
  }

  cur -> next = head;
  head = cur;
  return head;
}

// addKthPosition takes a linked list & a single ListNode, appends this ListNode
// at the k'th position of the list & returns the head of the new linked list
// 1 -> 2 -> 3 -> 4 -> 5
// assume that (k = 3):
// insert at 3rd position results this: 1 -> 2 -> 100 -> 3 -> 4 -> 5
ListNode* addKthPosition(ListNode *head, int k, ListNode *cur) {
  assert(length(head) >= k && k > 0);

  if (k == 1) {
    return addFirst(head, cur);
  }

  k -= 2;
  ListNode *dummy = head;
  while (k--) {
    dummy = dummy -> next;
  }

  ListNode *temp = dummy -> next;
  dummy -> next = cur;
  cur -> next = temp;
  return head;
}

// reverseList takes a linked list, reverses it iteratively and returns the new head
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

// reverseList takes a linked list, reverses it recursively and returns the new head
ListNode* reverseListRec(ListNode *head) {
  if (head == nullptr) {
    return nullptr;
  }
  if (head -> next == nullptr) {
    return head;
  }

  ListNode *temp = reverseListRec(head -> next);

  head -> next -> next = head;
  head -> next = nullptr;
  return temp;
}

int main() {
  return 0;
}

