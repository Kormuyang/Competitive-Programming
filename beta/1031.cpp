#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e4 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

vector<int> adj[mxN];
vector<int> dist(mxN, INF);
queue<pi> q;
int k, n, m, ans = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v; adj[u].emplace_back(v);
    }
    q.emplace(0, 1); dist[1] = 0;
    while(!q.empty()) {
        auto [d, u] = q.front(); q.pop();
        ans = max(ans, u);
        if(d == k) continue;
        for(auto v : adj[u]) if(d + 1 < dist[v]) dist[v] = d + 1, q.emplace(d + 1, v);
    }
    cout << ans << '\n';
    return 0;
}
