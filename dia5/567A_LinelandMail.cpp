#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++) {
        vector<long long> adj;
        vector<long long> ext;

        if (i) {
            adj.push_back(v[i-1]);
            ext.push_back(v[0]);
        }

        if (i + 1 < n) {
            adj.push_back(v[i+1]);
            ext.push_back(v.back());
        }

        long long mi = INF, ma = 0;

        for (const auto& x : adj) {
            mi = min(mi, llabs(x - v[i]));
        }

        for (const auto& x : ext) {
            ma = max(ma, llabs(x - v[i]));
        }

        cout << mi << " " << ma << '\n';
    }

}
