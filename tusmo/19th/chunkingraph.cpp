#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 5e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<int> adj[mxN];
int disc[mxN], low[mxN];
bool vis[mxN];
set<pi> bridge;
int n, m, idx = 0;

void dfs(int u, int p) {
    vis[u] = true;
    disc[u] = low[u] = ++idx;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs(v, u); low[u] = min(low[u], low[v]); if(low[v] > disc[u]) bridge.emplace(u, v);
        }
        else if(v != p) {
            low[u] = min(low[u], disc[v]);
        }
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v; adj[u].emplace_back(v); adj[v].emplace_back(u);
    }
    dfs(1, -1);
    cout << sz(bridge) + 1 << '\n';
    return 0;
}
