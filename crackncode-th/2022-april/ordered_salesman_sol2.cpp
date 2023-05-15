#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 4e2 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<vector<ll>> dp(mxN, vector<ll> (mxN, INF));
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w; dp[u][v] = dp[v][u] = min(dp[u][v], (ll) w);
    }
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
    ll ans = 0;
    for(int i = 2; i <= n; i++) ans += dp[i - 1][i];
    cout << ans << '\n';
    return 0;
}
