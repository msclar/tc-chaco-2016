#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int> > v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i].first;

        for (int i = 0; i < n; i++)
            cin >> v[i].second;

        sort(v.begin(), v.end());

        vector<int> dp(n+1);

        for (int i = n-1; i >= 0; i--) {
            dp[i] = max(dp[i+1],
                    v[i].second + dp[lower_bound(v.begin(), v.end(),
                                                 make_pair(v[i].first + k, 0)) -
                                     v.begin()]);
        }

        cout << dp[0] << '\n';
    }

    return 0;
}
