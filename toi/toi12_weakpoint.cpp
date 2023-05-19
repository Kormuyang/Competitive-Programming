#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int mxN = 5e5 + 1;

vector<int> adj[mxN];
bool vis[mxN], cycle[mxN];
int cnt[mxN];
int n, m; pi ans;

void dfs(int u, int p) {
    vis[u] = true;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs(v, u); cycle[u] |= cycle[v]; if(!cycle[v]) cnt[u] += cnt[v];
        }
        else if(v == m) cycle[u] = true;
    }
    if(cnt[u] > ans.second) ans = {u, cnt[u]};
    else if(cnt[u] == ans.second) ans.first = min(ans.first, u);
    cnt[u]++;
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, u, v; i <= n; i++) {
        cin >> u >> v; adj[u].emplace_back(v); adj[v].emplace_back(u);
    }
    dfs(m, 0);
    cout << ans.first << '\n' << ans.second << '\n';
    return 0;
}
