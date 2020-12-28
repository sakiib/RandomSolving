#include <bits/stdc++.h>
using namespace std;
 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* na, Arg1&& arg1, Args&&... args) {
  const char* c = strchr(na + 1, ',');
  cerr.write(na, c - na) << " : " << arg1 << " , ";
  __f(c + 1, args...);
}
#define endl "\n"
typedef long long LL;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
 
struct node {
  int cnt;
  bool endmark;
  node* nxt[2];
  node() {
    cnt = 0;
    endmark = false;
    for (int i = 0; i < 2; i++) nxt[i] = NULL;
  }
}*root;
 
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
    for (int i = 0; i < 2; i++) {
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
};
 
int a[ N ];
 
int solve(node* cur, int bit) {
  if (cur -> nxt[0] == NULL && cur -> nxt[1] == NULL) return 0;
  else if (cur -> nxt[0] == NULL) {
    return solve(cur -> nxt[1], bit - 1);
  }
  else if (cur -> nxt[1] == NULL) {
    return solve(cur -> nxt[0], bit - 1);
  }
  else {
    int res = 0;
    res = min(solve(cur -> nxt[1], bit - 1), solve(cur -> nxt[0], bit - 1));
    res += (1 << bit);
    return res;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  trie_int <int> tr(30);
  for (int i = 1; i <= n; i++) tr.insert(a[i]);
  cout << solve(root, 30) << endl;
  tr.del(root);
  return 0;
}
