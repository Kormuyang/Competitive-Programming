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

vector<t3> edges;
int parent[mxN];
int n, m, k;

int findParent(int child) {
    if(child == parent[child]) return child;
    return parent[child] = findParent(parent[child]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w; edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n; i++) parent[i] = i;
    priority_queue<int> pq;
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        auto [w, u, v] = edges[i];
        u = findParent(u), v = findParent(v);
        if(u != v) {
            ans += w; parent[v] = u; pq.emplace(w);
        }
    }
    while(k--) {
        ans -= pq.top(); pq.pop();
    }
    cout << ans << '\n';
    return 0;
}
