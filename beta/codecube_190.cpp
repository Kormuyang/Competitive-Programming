#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t4 tuple<int, int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<pi> adj[mxN];
bool vis[mxN], cycle[mxN];
ll cnt[mxN], ans[mxN];
int n, m;

bool dfs(int u, int p) {
    vis[u] = true;
    for(auto [v, i] : adj[u]) {
        if(!vis[v]) {
            if(dfs(v, u)) return (cycle[u] ? false : cycle[u] = true);
        }
        else if(v != p) return (cycle[v] = cycle[u] = true);
    }
    return false;
}

void dfs2(int u, int p, int x) {
    cnt[u] = 1;
    for(auto [v, i] : adj[u]) {
        if(v == p or cycle[v]) continue;
        dfs2(v, u, i); cnt[u] += cnt[v];
    }
    ans[x] = (n - cnt[u]) * cnt[u];
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v; adj[u].emplace_back(v, i); adj[v].emplace_back(u, i);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) if(cycle[i]) dfs2(i, 0, 0);
    for(int i = 1; i <= m; i++) cout << ans[i] << ' '; cout << '\n';
    return 0;
}
