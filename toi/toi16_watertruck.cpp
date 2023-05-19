#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 2e9;
const int mxN = 1e5 + 1;

vector<pi> adj[mxN], adj2[mxN];
vector<t3> edges;
int disc[mxN], low[mxN], scc[mxN], deg[mxN], dist[mxN];
bool vis[mxN];
vector<int> nodes;
stack<int> st;
priority_queue<pi, vector<pi>, greater<pi>> pq;
int n, m, idx, cnt, ans, ans2;

void tarjan(int u, int p) {
    disc[u] = low[u] = ++idx; st.emplace(u);
    for(auto [v, w] : adj[u]) {
        if(!disc[v]) {
            tarjan(v, u); low[u] = min(low[u], low[v]);
        }
        else if(v != p) low[u] = min(low[u], disc[v]);
    }
    if(low[u] == disc[u]) {
        cnt++;
        while(st.top() != u) {
            scc[st.top()] = cnt; st.pop();
        }
        scc[u] = cnt; st.pop();
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w; adj[u].emplace_back(v, w); adj[v].emplace_back(u, w); edges.emplace_back(w, u, v);
    }
    tarjan(0, -1);
    for(auto [w, u, v] : edges) {
        if(scc[u] == scc[v]) {
            ans += w; adj2[u].emplace_back(v, w); adj2[v].emplace_back(u, w); deg[u]++, deg[v]++;
        }
        else ans += 2 * w; 
    }
    edges.clear();
    for(int i = 0; i <= n; i++) if(deg[i] == 3) nodes.emplace_back(i);
    for(int i = 0; i < sz(nodes) - 1; i++) {
        memset(vis, false, sizeof(vis)); fill(dist, dist + mxN, INF);
        pq.emplace(0, nodes[i]); dist[nodes[i]] = 0;
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(vis[u]) continue; vis[u] = true;
            for(auto [v, w] : adj2[u]) if(!vis[v] and d + w < dist[v]) {
                dist[v] = d + w; pq.emplace(d + w, v);
            }
        }
        for(int j = i + 1; j < sz(nodes); j++) if(dist[nodes[j]] != INF) {
            edges.emplace_back(dist[nodes[j]], i, j);
        }
    }
    if(sz(edges) == 1) {
        auto [w, u, v] = edges[0]; ans2 = w;
    }
    else if(sz(edges)) {
        ans2 = INF;
        for(int i = 0; i < sz(edges) - 1; i++) for(int j = i + 1; j < sz(edges); j++) {
            auto [wi, ui, vi] = edges[i]; auto [wj, uj, vj] = edges[j];
            if(ui == uj or ui == vj or vi == uj or vi == vj) continue;
            ans2 = min(ans2, wi + wj);
        }
    }
    cout << ans + ans2 << '\n';
    return 0;
}
