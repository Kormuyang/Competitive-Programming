#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e6 + 7;
const int mxN = 1e5 + 1;

vector<pi> adj[mxN];
int a[mxN], vis[mxN];
int n, s, t, r;
ll ans;

ll dfs(int u, int p, int tar) {
    ll ret = (vis[u] ? 0 : a[u]);
    if(vis[u] = 0) vis[u] = 1;
    if(u == tar) {
        vis[u] = 2; return ret;
    }
    for(auto [v, w] : adj[u]) {
        if(v == p) continue;
        ll res = dfs(v, u, tar);
        if(res != -INF) {
            vis[u] = 2; return ret - w + res;
        }
    }
    if(vis[u] == 1) vis[u] = 0;
    return -INF;
}

ll dfs2(int u, int p) {
    ll ret = 0;
    for(auto [v, w] : adj[u]) {
        if(v == p or vis[v]) continue;
        ret += max(0ll, a[v] - 2 * w + dfs2(v, u));
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1, u, v, w; i <= n - 1; i++) {
        cin >> u >> v >> w; adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> s >> t >> r;
    ans = dfs(s, 0, r) + dfs(r, 0, t);
    for(int i = 1; i <= n; i++) if(vis[i]) ans += dfs2(i, 0);
    cout << ans << '\n';
    return 0;
}
