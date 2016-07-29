#include <bits/stdc++.h>

using namespace std;

long long dp[100][100];

int main() {
    int n, k;

    while (cin >> n >> k && n) {
        vector<int> v(n);

        for (int& x : v)
            cin >> x;

        long long ans = 0;

        for (int kk = 0; kk < k; kk++) {
            for (int i = 0; i < n; i++) {
                if (kk == 0) {
                    dp[i][kk] = 1;
                } else {
                    dp[i][kk] = 0;

                    for (int j = 0; j < i; j++) {
                        if (v[i] > v[j]) {
                            dp[i][kk] += dp[j][kk-1];
                        }
                    }
                }

                if (kk == k-1)
                    ans += dp[i][kk];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
