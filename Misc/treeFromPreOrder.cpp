#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct Node {
    int val;
    Node *left, *right;
    Node(int v = 0) {
        val = v;
        left = NULL, right = NULL;
    }
};

Node* generateTree(int mx, queue <int> &q) {
    if (q.empty()) return NULL;
    int cur = q.front(); q.pop();
    Node *now = new Node(cur);
    if (!q.empty() && q.front() < now -> val) {
        now -> left = generateTree(now -> val, q);
    }
    if (!q.empty() && q.front() > now -> val && q.front() < mx) {
        now -> right = generateTree(mx, q);
    }
    return now;
}

int main() {
    //freopen("input.txt", "r", stdin);

    int n;
    queue <int> q;

    while (cin >> n) {
        q.push(n);
    }

    Node *root = generateTree(inf, q);
    return 0;
}

