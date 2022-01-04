#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 3e5 + 5;
vector <pair <long long, long long> > intervals[N];

template <typename T> class treap {
public:
  struct node {
    T val;
    int prior, sz;
    node *l, *r;
    long long sum;
  };
  typedef node* pnode;
  pnode root;
  treap() {
    root = NULL;
  }
  inline long long get_sum(pnode t) {
    return t? t -> sum: 0;
  }
  inline int size(pnode t) {
    return t? t -> sz : 0;
  }
  inline void update_size(pnode t) {
    if (t) t -> sz = size(t -> l) + size(t ->r) + 1;
    if (t) t -> sum = get_sum(t -> l) + get_sum(t -> r) + (t -> val).first;
  }
  inline pnode initialize(T x) {
    pnode ret = (pnode)malloc(sizeof(node));
    ret -> val = x, ret -> prior = rand(), ret -> sz = 1, ret -> sum = x.first;
    ret -> l = NULL, ret -> r = NULL;
    return ret;
  }
  inline void split(pnode t, pnode &l, pnode &r, T key) {
    if (!t) l = NULL, r = NULL;
    else if (t -> val <= key) split(t -> r, t -> r, r, key), l = t;
    else split(t -> l, l, t -> l, key), r = t;
    update_size(t);
  }
  inline void merge(pnode &t, pnode l, pnode r) {
    if (!l || !r) t = l ? l : r;
    else if (l -> prior > r -> prior) merge(l -> r, l -> r, r), t = l;
    else merge(r -> l, l, r -> l), t = r;
    update_size(t);
  }
  inline void insert(pnode it, pnode &t) {
    if (!t) t = it;
    else if (it -> prior > t -> prior) {
      split(t, it -> l, it -> r, it -> val), t = it;
    }
    else {
      insert(it, t -> val <= it -> val ? t -> r : t -> l);
    }
    update_size(t);
  }
  inline void erase(T key, pnode &t) {
    if (!t) return;
    if (t -> val == key) {
      pnode temp = t;
      merge(t, t -> l, t -> r);
      free(temp);
    }
    else erase(key, t -> val < key ? t -> r : t -> l);
    update_size(t);
  }
  inline int less(T s, pnode t) {
    if (!t) return 0;
    if (t -> val >= s) return less(s, t -> l);
    return size(t -> l) + 1 + less(s, t -> r);
  }
  inline int less_equal(T s, pnode t) {
    if (!t) return 0;
    if (t -> val > s) return less_equal(s, t -> l);
    return size(t -> l) + 1 + less_equal(s, t -> r);
  }

  long long largest_sum(pnode root, int k) {
    if (!root) {
      return 0;
    }
    if (!k) {
      return 0;
    }
    if (size(root) <= k) {
      return get_sum(root);
    }
    if (size(root -> r) >= k) {
      return largest_sum(root -> r, k);
    }
    if (size(root -> r) + 1 == k) {
      return get_sum(root -> r) + (root -> val).first;
    }
    return get_sum(root -> r) + (root -> val).first + largest_sum(root -> l, k - size(root -> r) - 1);
  }
  long long largest_sum(int k) {
    return largest_sum(root, k);
  }
  inline void print(pnode root) {
    if (root == NULL) return;
    print(root -> l);
    cerr << root -> val.first << " ";
    print(root -> r);
  }
  inline int size() {
    return size(root);
  }
  inline void insert(T val) {
    insert(initialize(val), root);
  }
  inline void erase(T key) {
    erase(key, root);
  }
  inline int less_equal(T s) {
    return less_equal(s, root);
  }
  inline int less(T s) {
    return less(s, root);
  }
  inline void print() {
    print(root); cout << "\n";
  }
};

void reset() {
  for (int i = 1; i <= (int)3e5 + 1; i++) {
    intervals[i].clear();
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int d, n, k;
    cin >> d >> n >> k;

    reset();

    treap <pair <LL, int> > tr;

    for (int i = 1; i <= n; i++) {
      int val, l, r;
      cin >> val >> l >> r;
      intervals[l].push_back({val, i});
      intervals[r + 1].push_back({val, -i});
    }

    LL ans = 0;
    for (int i = 1; i <= d; i++) {
      for (auto [val, id]: intervals[i]) {
        if (id > 0) {
          tr.insert({val, id});
        } else {
          tr.erase({val, - id});
        }
      }
      ans = max(ans, tr.largest_sum(k));
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  return 0;
}
