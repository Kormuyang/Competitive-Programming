#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

void tarjan(int u, int idx, vector<vector<int>> &adj, vector<int> &disc, vector<int> & low, vector<int> &scc, vector<bool> &inpath, stack<int> &path) {
    disc[u] = low[u] = ++idx;
    path.emplace(u); inpath[u] = true;
    for(auto v : adj[u]) {
        if(!disc[v]) {
            tarjan(v, idx, adj, disc, low, scc, inpath, path); low[u] = min(low[u], low[v]);
        }
        else if(inpath[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == disc[u]) {
        int t;
        do {
            t = path.top(); path.pop();
            inpath[t] = false; scc[t] = u;
        } while(t != u);
    }
    return;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pi> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    vector<int> neg(m + 1);
    for(int i = 1, u, v; i <= m / 2; i++) {
        cin >> u >> v; neg[u] = v, neg[v] = u;
    }
    vector<vector<int>> adj(m + 1);
    for(auto [u, v] : a) {
        adj[neg[u]].emplace_back(v); adj[neg[v]].emplace_back(u);
    }
    vector<int> disc(m + 1), low(m + 1), scc(m + 1);
    vector<bool> inpath(m + 1); stack<int> path;
    int idx = 0;
    for(int i = 1; i <= m; i++) if(!disc[i]) tarjan(i, idx, adj, disc, low, scc, inpath, path);
    bool chk = true;
    for(int i = 1; i <= m; i++) if(scc[i] == scc[neg[i]]) {
        chk = false; break;
    }
    cout << (chk ? 'Y' : 'N');
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i = 0; i < 5; i++) solve();
    cout << '\n';
    return 0;
}
