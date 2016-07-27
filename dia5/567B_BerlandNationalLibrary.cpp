#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        char signal;
        int x;
        cin >> signal >> x;

        v[i] = x * (signal == '+' ? 1 : -1);
    }

    vector<int> v2;

    set<int> entered;

    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            entered.insert(v[i]);
        } else if (entered.count(-v[i]) == 0) {
            v2.push_back(-v[i]);
        }
    }

    vector<int> v3 = v2;
    v3.insert(v3.end(), v.begin(), v.end());

    entered.clear();
    int ans = 0;

    for (int i : v3) {
        if (i > 0) {
            entered.insert(i);
        } else {
            assert(entered.erase(-i));
        }
        ans = max(ans, (int)entered.size());
    }

    cout << ans << endl;

    return 0;
}
