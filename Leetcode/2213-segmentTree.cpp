const int N = 1e5 + 5;

struct Node {
  int maxLen;
  int startIdx, endIdx;
  int prefixLen, suffixLen;
  Node(): maxLen(0), startIdx(0), endIdx(0), prefixLen(0), suffixLen(0) {}
} segmentTree[4 * N];

Node combine(Node &l, Node &r, string &s) {
  Node curNode = Node();

  if (s[l.endIdx] == s[r.startIdx]) {
    curNode.maxLen = max({l.maxLen, r.maxLen, l.suffixLen + r.prefixLen});

    if (l.prefixLen == l.endIdx - l.startIdx + 1) {
      curNode.prefixLen = l.prefixLen + r.prefixLen;
    } else {
      curNode.prefixLen = l.prefixLen;
    }

    if (r.suffixLen == r.endIdx - r.startIdx + 1) {
      curNode.suffixLen = r.suffixLen + l.suffixLen;
    } else {
      curNode.suffixLen = r.suffixLen;
    }


  } else {
    curNode.maxLen = max(l.maxLen, r.maxLen);
    curNode.prefixLen = l.prefixLen;
    curNode.suffixLen = r.suffixLen;
  }

  curNode.startIdx = l.startIdx;
  curNode.endIdx = r.endIdx;

  return curNode;
}

void build(int node, int b, int e, string & s) {
  if (b > e) {
    return;
  }

  if (b == e) {
    segmentTree[node].maxLen = 1;
    segmentTree[node].startIdx = b, segmentTree[node].endIdx = b;
    segmentTree[node].prefixLen = 1, segmentTree[node].suffixLen = 1;
    return;
  }

  int l = node << 1, r = l | 1, m = (b + e) >> 1;

  build(l, b, m, s);
  build(r, m + 1, e, s);

  segmentTree[node] = combine(segmentTree[l], segmentTree[r], s);
}

void update(int node, int b, int e, int pos, char ch, string & s) {
  if (pos > e || pos < b || b > e) {
    return;
  }

  if (pos == b && b == e) {
    s[pos] = ch;
    segmentTree[node].maxLen = 1;
    segmentTree[node].startIdx = b, segmentTree[node].endIdx = b;
    segmentTree[node].prefixLen = 1, segmentTree[node].suffixLen = 1;
    return;
  }

  int l = node << 1, r = l | 1, m = (b + e) >> 1;

  if (pos <= m) {
    update(l, b, m, pos, ch, s);
  } else {
    update(r, m + 1, e, pos, ch, s);
  }

  segmentTree[node] = combine(segmentTree[l], segmentTree[r], s);
}

class Solution {
  public:
    vector <int> longestRepeating(string s, string queryCharacters, vector <int> &queryIndices) {
      int len = s.size();
      s = "#" + s;

      build(1, 1, len, s);

      vector <int> ans;
      for (int i = 0; i < (int)queryCharacters.size(); i++) {
        update(1, 1, len, queryIndices[i] + 1, queryCharacters[i], s);
        ans.push_back(segmentTree[1].maxLen);
      }

      return ans;
    }
};
