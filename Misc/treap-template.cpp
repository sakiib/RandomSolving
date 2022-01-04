#include<bits/stdc++.h>
using namespace std;

// TODO:
//  - fix the erase()

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> struct treap {
  struct node {
    node *l, *r;
    T key;
    long long sum;
    int prior;
    int sz;
    node(T id): l(nullptr), r(nullptr), key(id), sum(id.first), prior(rnd()), sz(1) {}
  };

  node *root;
  treap() {
    root = nullptr;
  }
  long long get_sm(node *t) {
    return t? t -> sum: 0;
  }
  int get_sz(node *t) {
    return t? t -> sz: 0;
  }
  int size() {
    return get_sz(root);
  }
  void upd(node *t) {
    if (!t) {
      return;
    }
    t -> sz = get_sz(t -> l) + get_sz(t -> r) + 1;
    t -> sum = get_sm(t -> l) + get_sm(t -> r) + (t -> key).first;
  }
  void split(node *t, T pos, node *&l, node *&r) {
    if (t == nullptr) {
      l = r = nullptr;
      return;
    }
    if (t->key <= pos) {
      split(t->r, pos, l, r);
      t->r = l;
      l = t;
      upd(l);
    } else {
      split(t->l, pos, l, r);
      t->l = r;
      r = t;
      upd(r);
    }
  }
  node* merge(node *l, node *r) {
    if (!l || !r) return l? l : r;
    if (l->prior < r->prior) {
      l->r = merge(l->r, r);
      upd(l);
      return l;
    }
    r->l = merge(l, r->l);
    upd(r);
    return r;
  }
  void insert(T id) {
    node *l, *r;
    split(root, id, l, r);
    root = merge(merge(l, new node(id)), r);
  }
  void erase(T id, node *t) {
    if (!t) {
      return;
    }
    if (id == t -> key) {
      root = merge(t -> l, t -> r);
    } else {
      erase(id, t -> key < id? t -> r: t -> l);
    }
    upd(root);
  }
  void erase(T id) {
    erase(id, root);
  }
  T kth(node *t, int k) {
    int cnt = get_sz(t -> l);
    if (cnt == k - 1) {
      return t -> key;
    }
    if (cnt >= k) {
      return kth(t -> l, k);
    }
    return kth(t -> r, k - cnt - 1);
  }
  T kth(int k) {
    return size() < k? T{}: kth(root, k);
  }
  long long largest_sum(node *t, int k) {
    if (!t || !k) {
      return 0;
    }
    if (get_sz(t) <= k) {
      return t -> sum;
    }
    if (get_sz(t -> r) >= k) {
      return largest_sum(t -> r, k);
    }
    if (get_sz(t -> r) + 1 == k) {
      return get_sm(t -> r) + (t -> key).first;
    }
    return get_sm(t -> r) + (t -> key).first + largest_sum(t -> l, k - get_sz(t -> r) - 1);
  }
  long long largest_sum(int k) {
    return largest_sum(root, k);
  }
  vector<T> ans;
  void dfs(node* cur) {
    if(!cur) return;
    ans.push_back(cur -> key);
    dfs(cur -> l);
    dfs(cur -> r);
  }
  vector<T> get() {
    ans.clear();
    dfs(root);
    return ans;
  }
};

int main() {
  return 0;
}
