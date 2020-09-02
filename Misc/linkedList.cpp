#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int v = 0) {
        val = v;
        next = NULL;
    }
};

Node *head;

void insertLast(int val = 0) {
    Node *now = new Node(val);
    if (head == NULL) {
        head = now;
        return;
    }
    Node *temp = head;
    while (temp -> next != NULL) temp = temp -> next;
    temp -> next = now;
}

void insertFirst(int val = 0) {
    Node *now = new Node(val);
    if (head == NULL) {
        head = now;
        return;
    }
    Node *temp = head;
    head = now;
    now -> next = temp;
}

int main() {
    head = new Node(10);
    insertLast(20);
    insertLast(30);
    insertFirst(5);
    insertLast(50);
    insertFirst(1);
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> val << endl;
        temp = temp -> next;
    }
    return 0;
}
