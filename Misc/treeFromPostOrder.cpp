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

Node* generateTree(int mx, stack <int> &st) {
    if (st.empty()) return NULL;
    int cur = st.top(); st.pop();
    Node *now = new Node(cur);
    //cout << now -> val << endl;
    if (!st.empty() && st.top() < now -> val) {
        //cout << "going left" << endl;
        now -> right = generateTree(now -> val, st);
    }
    if (!st.empty() && st.top() > now -> val && st.top() < mx) {
        //cout << "going right" << endl;
        now -> left = generateTree(mx, st);
    }
    return now;
}

void preOrder(Node *cur) {
    if (cur == NULL) return;
    cout << cur -> val << endl;
    if (cur -> right) preOrder(cur -> right);
    if (cur -> left) preOrder(cur -> left);
}

int main() {
    freopen("input.txt", "r", stdin);

    int n;
    stack <int> st;

    while (cin >> n) {
        st.push(n);
    }

    Node *root = generateTree(inf, st);
    preOrder(root);
    return 0;
}


