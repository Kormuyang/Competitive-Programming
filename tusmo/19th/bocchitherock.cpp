#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<pi> adj[mxN];
vector<int> dist(mxN, INF);
bool vis[mxN];
priority_queue<pi, vector<pi>, greater<pi>> pq;
int n, m, k, ans = INF;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w; adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    pq.emplace(0, 0); dist[0] = 0;
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(vis[u]) continue; vis[u] = true;
        for(auto [v, w] : adj[u]) {
            if(vis[v]) continue;
            if(d + w < dist[v]) dist[v] = d + w, pq.emplace(d + w, v);
        }
    }
    cin >> k;
    for(int i = 1, x, c; i <= k; i++) {
        cin >> x >> c; ans = min(ans, dist[x] + c);
    }
    cout << ans << '\n';
    return 0;
}
