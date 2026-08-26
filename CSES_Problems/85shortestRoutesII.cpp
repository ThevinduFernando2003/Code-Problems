#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    const long long INF = 1e18;
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (long long)c);
    }

    for (int mid = 1; mid <= n; mid++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][mid] < INF && dist[mid][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
                }
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] >= INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }

    return 0;
}
