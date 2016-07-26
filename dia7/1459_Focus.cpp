#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool interval_lt(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int doit(vector<pair<int, int> > &v) {
    sort(v.begin(), v.end(), interval_lt);
    
    int covered = 0, chosen = 0;

    for (int i = 0; i < v.size(); i++)
        if (v[i].first > covered) {
            covered = v[i].second;
            chosen++;
        }

    return chosen;
}

int main() {

    int n;

    ios::sync_with_stdio(false);

    while (cin >> n) {
        vector<pair<int, int> > v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;

        cout << doit(v) << '\n';
    }

    return 0;
}
