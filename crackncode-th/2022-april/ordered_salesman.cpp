#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<ll, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 4e2 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<pi> adj[mxN];
vector<vector<ll>> dist(mxN, vector<ll> (mxN, INF));
bool vis[mxN][mxN];
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w; adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    priority_queue<t3, vector<t3>, greater<t3>> pq;
    pq.emplace(0, 1, 1); dist[1][1] = 0;
    while(!pq.empty()) {
        auto [d, c, u] = pq.top(); pq.pop();
        if(c == n) {
            cout << d << '\n'; return 0;
        }
        if(vis[c][u]) continue;
        vis[c][u] = true;
        for(auto [v, w] : adj[u]) {
            if(v == c + 1 and !vis[c + 1][v] and d + w < dist[c + 1][v]) {
                dist[c + 1][v] = d + w; pq.emplace(d + w, c + 1, v);
            }
            else if(v != c + 1 and !vis[c][v] and d + w < dist[c][v]) {
                dist[c][v] = d + w; pq.emplace(d + w, c, v);
            }
        }
    }
    return 0;
}
