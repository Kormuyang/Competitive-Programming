#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 3e2 + 1;
const int mxK = 2e3 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<t3> adj[mxN];
int dp[mxK][mxN];
int n, m, k, s, t, ans = -1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k >> s >> t;
    for(int i = 1, u, v, c, w; i <= m; i++) {
        cin >> u >> v >> c >> w; adj[u].emplace_back(v, c, w); adj[v].emplace_back(u, c, w);
    }
    dp[0][s] = 0;
    for(int i = 0; i < k; i++) for(int j = 1; j <= n; j++) {
        if(dp[i][j] == -1) continue;
        for(auto [v, c, w] : adj[j]) {
            if(i + w > k) continue;
            dp[i + w][v] = max(dp[i + w][v], dp[i][j] + c);
        }
    }
    for(int i = 1; i <= k; i++) ans = max(ans, dp[i][t]);
    if(ans == -1) cout << "Impossible\n";
    else cout << ans << '\n';
    return 0;
}
