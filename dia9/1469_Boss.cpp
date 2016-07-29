#include <bits/stdc++.h>

using namespace std;

const int INF = 1000;

int dfs(vector<vector<int>> &g,
        int v,
        vector<int> &min_edad,
        vector<int> &edades,
        vector<int> &empleado) {
  if (min_edad[v] != -1)
    return min_edad[v];

  int resp = INF;

  for (int i = 0; i < g[v].size(); i++) {
    int me = dfs(g, g[v][i], min_edad, edades, empleado);
    resp = min(resp, edades[empleado[g[v][i]]]);
    resp = min(resp, me);
  }

  min_edad[v] = resp;
  return resp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, q;

  while (cin >> n >> m >> q) {
    vector<int> edades(n);
    vector<int> vertice_correspondente(n);
    vector<int> empleado(n);

    for (int i = 0; i < n; i++) {
      cin >> edades[i];
      empleado[i] = i;
      vertice_correspondente[i] = i;
    }

    vector<vector<int> > g(n);

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      g[b-1].push_back(a-1);
    }

    for (int i = 0; i < q; i++) {
      char tipo;
      cin >> tipo;

      if (tipo == 'P') {
        int x;
        cin >> x;

        vector<int> min_edad(n, -1);

        int resp = dfs(g, vertice_correspondente[x-1], min_edad,
                       edades, empleado);

        if (resp == INF) {
          cout << "*\n";
        } else {
          cout << resp << '\n';
        }
      } else {
        int a, b;
        cin >> a >> b;

        swap(vertice_correspondente[a-1], vertice_correspondente[b-1]);
        empleado[vertice_correspondente[a-1]] = a-1;
        empleado[vertice_correspondente[b-1]] = b-1;
      }
    }

  }

  return 0;
}













