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

vector<int> adj[mxN];
vector<vector<int>> dist(2, vector<int> (mxN, INF));
bool vis[2][mxN];
vector<int> edges[mxN];
multiset<int> mx_dist;
int ans[mxN];
int n, m, p, a, b;

void bfs(int src, int k) {
    queue<int> q; q.emplace(src); dist[k][src] = 0;
    while(!q.empty()) {
        auto u = q.front(); q.pop(); vis[k][u] = true;
        for(auto v : adj[u]) if(!vis[k][v]) dist[k][v] = dist[k][u] + 1, q.emplace(v);
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> p >> a >> b;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v; adj[u].emplace_back(v); adj[v].emplace_back(u);
    }
    bfs(a, 0); bfs(b, 1);
    for(int i = 1; i <= n; i++) {
        edges[dist[1][i]].emplace_back(i); mx_dist.emplace(dist[0][i]);
    }
    for(int i = 0; i <= n; i++) {
        for(auto v : edges[i]) mx_dist.erase(mx_dist.find(dist[0][v]));
        if(!mx_dist.empty()) ans[i] = *mx_dist.rbegin();
    }
    while(p--) {
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
    return 0;
}
