#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long LL;
const int inf = 2e9;

struct VeniceSet {
   multiset < LL > S;
   LL water_lvl = 0;
   inline void Add(LL val) {
      S.insert(val - water_lvl);
   }
   inline void UpdateAll(LL val) {
      water_lvl += val;
   }
   inline LL GetSize() {
      return S.size();
   }
   inline LL GetMin() {
      return ( * S.begin() + water_lvl);
   }
   inline void Remove(LL val) {
      S.erase(S.find(val - water_lvl));
   }
}S;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int q;
   cin >> q;
   while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
         LL val;
         cin >> val;
         S.Add(val);
      } else if (type == 2) {
         LL val;
         cin >> val;
         S.UpdateAll(val);
      } else {
         LL val = S.GetMin();
         S.Remove(val);
         cout << val << endl;
      }
   }
   return 0;
}
