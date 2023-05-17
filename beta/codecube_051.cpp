#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 2e2 + 1;

int a[mxN];
vector<vector<int>> dist(mxN, vector<int> (mxN, INF)), dp(1 << 16, vector<int> (16, INF));
int n, m, k;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) cin >> a[i]; a[k] = n;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w; dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }
    for(int l = 1; l <= n; l++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
    }
    for(int i = 0; i < k; i++) dp[1 << i][i] = dist[1][a[i]];
    for(int i = 1; i < (1 << (k + 1)) - 1; i++) for(int j = 0; (1 << j) <= i; j++) {
        if(dp[i][j] == INF) continue;
        for(int l = 0; l <= k; l++) if((i | (1 << l)) != i) {
            dp[i | (1 << l)][l] = min(dp[i | (1 << l)][l], dp[i][j] + dist[a[j]][a[l]]);
        }
    }
    cout << dp[(1 << (k + 1)) - 1][k] << '\n';
    return 0;
}
