class Solution {
public:
  template <typename T> class treap {
    public:
      struct node {
        T val, prior, sz;
        node *l, *r;
      };
      typedef node* pnode;
      pnode root;
      treap() {
        root = NULL;
      }
      inline int size(pnode t) {
        return t? t -> sz : 0;
      }
      inline int size() {
        return size(root);
      }
      inline void update_size(pnode t) {
        if (t) t -> sz = size(t -> l) + size(t ->r) + 1;
      }
      inline pnode initialize(T x) {
        pnode ret = (pnode)malloc(sizeof(node));
        ret -> val = x, ret -> prior = rand(), ret -> sz = 1;
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
      inline void insert(T val) {
        insert(initialize(val), root);
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
      inline void erase(T key) {
        erase(key, root);
      }
      inline int less(T s, pnode t) {
        if (!t) return 0;
        if (t -> val >= s) return less(s, t -> l);
        return size(t -> l) + 1 + less(s, t -> r);
      }
      inline int less(T s) {
        return less(s, root);
      }
      inline int less_equal(T s, pnode t) {
        if (!t) return 0;
        if (t -> val > s) return less_equal(s, t -> l);
        return size(t -> l) + 1 + less_equal(s, t -> r);
      }
      inline int less_equal(T s) {
        return less_equal(s, root);
      }
      inline void print(pnode root) {
        if (root == NULL) return;
        print(root -> l);
        cerr << root -> val << " ";
        print(root -> r);
      }
      inline void print() {
        print(root); cout << "\n";
      }
    };

    int smallestDistancePair(vector<int>& nums, int k) {
      int lo = 0, hi = 1000000, ret = -1;
      treap <int> t;
      sort(nums.begin(), nums.end(), greater <int>());
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int cnt = 0;
        t.root = NULL;
        for (int i = nums.size() - 1; i >= 0; i--) {
          int x = nums[i];
          cnt += (t.size() - t.less(x - mid));
          t.insert(x);
        }
        if (cnt >= k) ret = mid, hi = mid - 1;
        else lo = mid + 1;
      }
      return ret;
    }
};
