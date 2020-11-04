#include <bits/stdc++.h>
using namespace std;

struct node {
  int cnt;
  bool endmark;
  node* nxt[26];
  node() {
    cnt = 0;
    endmark = false;
    for (int i = 0; i < 26; i++) nxt[i] = NULL;
  }
}*root;

struct trie_string {
  inline int get_id(char c) {
    return c - 'a' + 1;
  }
  inline void insert(string &s) {
    int l = s.size();
    node *cur = root;
    for (int i = 0; i < l; i++) {
      int id = get_id(s[i]);
      if (cur -> nxt[id] == NULL) {
        cur -> nxt[id] = new node();
      }
      cur = cur -> nxt[id];
    }
    cur -> endmark = true;
  }
  inline bool find(string &s) {
    int l = s.size();
    node *cur = root;
    for (int i = 0; i < l; i++) {
      int id = get_id(s[i]);
      if (cur -> nxt[id] == NULL) return false;
      cur = cur -> nxt[id];
    }
    return cur -> endmark;
  }
};

struct trie_num {
  int mx = 29;
  inline bool check(int n, int pos) {
    return (bool)(n&(1 << pos));
  }
  inline int on(int n, int pos) {
    return n |= (1 << pos);
  }
  inline void insert(int num) {
    node *cur = root;
    for (int i = mx; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id] == NULL) {
        cur -> nxt[id] = new node();
      }
      cur = cur -> nxt[id];
    }
    cur -> endmark = true;
  }
  inline bool find(int num) {
    node *cur = root;
    for (int i = mx; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id] == NULL) return false;
      cur = cur -> nxt[id];
    }
    return cur -> endmark;
  }
  inline int maxxor(int num) {
    node *cur = root;
    int ans = 0;
    for (int i = mx; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id^1] != NULL) {
        ans = on(ans, i);
        cur = cur -> nxt[id^1];
      }
      else if (cur -> nxt[id] != NULL) {
        cur = cur -> nxt[id];
      }
    }
    return ans;
  }
}tr;

template <typename T> class trie_int {
public:
  int mx_bit = -1;
  trie_int(int sz) {
    mx_bit = sz;
    root = new node();
  }
  inline bool check(T n, int pos) {
    return (bool)(n&(1LL << pos));
  }
  inline T on(T n, int pos) {
    return n |= (1LL << pos);
  }
  inline void del(node* cur) {
    for (int i = 0; i < 26; i++) {
      if (cur -> nxt[i]) del(cur -> nxt[i]);
    }
    delete(cur);
  }
  inline void insert(T num) {
    node *cur = root;
    for (int i = mx_bit; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id] == NULL) {
        cur -> nxt[id] = new node();
      }
      cur = cur -> nxt[id];
    }
    cur -> endmark = true;
  }
  inline bool find(T num) {
    node *cur = root;
    for (int i = mx_bit; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id] == NULL) return false;
      cur = cur -> nxt[id];
    }
    return cur -> endmark;
  }
  inline T maxxor(T num) {
    node *cur = root;
    T ans = 0;
    for (int i = mx_bit; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id^1] != NULL) {
        ans = on(ans, i);
        cur = cur -> nxt[id^1];
      }
      else if (cur -> nxt[id] != NULL) {
        cur = cur -> nxt[id];
      }
    }
    return ans;
  }
  inline T minxor(T num) {
    node *cur = root;
    T ans = 0;
    for (int i = mx_bit; i >= 0; i--) {
      int id = check(num, i);
      if (cur -> nxt[id] != NULL) {
        cur = cur -> nxt[id];
      }
      else if (cur -> nxt[id^1] != NULL) {
        ans = on(ans, i);
        cur = cur -> nxt[id^1];
      }
    }
    return ans;
  }
};

const int inf = 1e9;

struct trie {
  inline void insert(int num) {
    vector <int> v;
    num += inf;
    while (num) v.push_back(num%10), num /= 10;
    int l = v.size();
    node *cur = root;
    for (int i = 0; i < l; i++) {
      int id = v[i];
      if (cur -> nxt[id] == NULL) {
        cur -> nxt[id] = new node();
      }
      cur = cur -> nxt[id];
      cur -> cnt++;
    }
  }
  inline void remove(int num) {
    vector <int> v;
    num += inf;
    while (num) v.push_back(num%10), num /= 10;
    int l = v.size();
    node *cur = root;
    for (int i = 0; i < l; i++) {
      int id = v[i];
      cur = cur -> nxt[id];
      cur -> cnt--;
    }
  }
  inline int count(int num) {
    vector <int> v;
    num += inf;
    while (num) v.push_back(num%10), num /= 10;
    int l = v.size();
    node *cur = root;
    for (int i = 0; i < l; i++) {
      int id = v[i];
      if (cur -> nxt[id] == NULL) return 0;
      if (cur -> nxt[id] -> cnt == 0) return 0;
      cur = cur -> nxt[id];
    }
    return cur -> cnt;
  }
}t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  trie_int <long long> tr(62);
  tr.insert(10000000000);
  tr.insert(2);
  cout << tr.minxor(10000000000) << endl;
  return 0;
}


