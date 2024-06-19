#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  int total = 0;
  for (int &value : a) {
    cin >> value;
    total |= value;
  }
  vector<array<int, 2>> st1 = {{0, 0}}, st2;
  deque<array<int, 2>> hull;
  vector<int> ans(n), nxt(n), push(n, -n);
  for (int i = 0, j = 0; i < n; i++) {
    if (i > 0) {
      push[i] = max(push[i - 1], push[i]);
    }
    j = max(j, i);
    while (j < n && (st1.back()[1] | (st2.empty() ? 0 : st2.back()[1])) < total) {
      st1.push_back({a[j], st1.back()[1] | a[j]});
      j++;
    }
    if (j < n) {
      push[j] = max(push[j], i);
    }
    nxt[i] = j;
    if ((st1.back()[1] | (st2.empty() ? 0 : st2.back()[1])) == total) {
      while (!hull.empty() && hull.back()[1] > j - i) {
        hull.pop_back();
      }
      hull.push_back({j, j - i});
    }
    while (!hull.empty() && hull.front()[0] <= i) {
      hull.pop_front();
    }
    ans[i] = min(i - push[i] + 1, hull.empty() ? n : hull.front()[1]);
    if (i == j) {
      continue;
    }
    if (st2.empty()) {
      while (st1.size() > 1) {
        st2.push_back({st1.back()[0], (st2.empty() ? 0 : st2.back()[1]) | st1.back()[0]});
        st1.pop_back();
      }
    }
    st2.pop_back();
  }
  while (q--) {
    int k;
    cin >> k;
    cout << ans[k] << "\n";
  }
}
