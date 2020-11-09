#include <bits/stdc++.h>
using namespace std;

struct node {
    bool isword;
    node * next[26];
    node() {
        isword = false;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
}* root;

struct trie_string {
    inline int get_id(char ch) {
        return (ch - 'a');
    }
    inline void insert(string &s) {
        int l = s.size();
        node * cur = root;
        for (int i = 0; i < l; i++) {
            int id = get_id(s[i]);

            if (cur -> next[id] == nullptr) cur -> next[id] = new node();

            cur = cur -> next[id];
        }
        cur -> isword = true;
    }
    inline bool find(string &s) {
        int l = s.size();
        node * cur = root;
        for (int i = 0; i < l; i++) {
            int id = get_id(s[i]);

            if (cur -> next[id] == nullptr) return false;

            cur = cur -> next[id];
        }
        return cur -> isword;
    }
    inline node* have_prefix(string &s) {
        int l = s.size();
        node * cur = root;
        for (int i = 0; i < l; i++) {
            int id = get_id(s[i]);

            if (cur -> next[id] == nullptr) return nullptr;

            cur = cur -> next[id];
        }
        return cur;
    }
};

void print_matching_words(node *current, string word, bool added) {
    if (current == nullptr) return;

    if (current -> isword && added) {
        cout << word << "\n";
    }

    for (int i = 0; i < 26; i++) {
        if (current -> next[i] != nullptr) {
            print_matching_words(current -> next[i], word + char(i + 'a'), true);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    trie_string trie;
    root = new node();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string word;
        cin >> word;

        trie.insert(word);
    }

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ":" << "\n";

        string word;
        cin >> word;

        node *matched = trie.have_prefix(word);
        if (!matched) {
            cout << "No match." << "\n";
        }
        else {
            print_matching_words(matched, word, false);
        }
    }
    return 0;
}

