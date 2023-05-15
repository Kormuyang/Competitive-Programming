#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 1;
const int mxT = 1e2 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<pi> edges[mxT];
int parent[mxN];
int n, m, s, e, ans = INF;

int findParent(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findParent(parent[u]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> s >> e;
    for(int i = 1, u, v, t; i <= m; i++) {
        cin >> u >> v >> t; edges[t].emplace_back(u, v);
    }
    for(int i = 1; i < mxT; i++) {
        iota(parent + 1, parent + n + 1, 1);
        int j = i;
        while(j < mxT and findParent(s) != findParent(e)) {
            for(auto [u, v] : edges[j]) {
                u = findParent(u), v = findParent(v);
                if(u != v) parent[v] = u;
            }
            j++;
        }
        if(findParent(s) == findParent(e)) ans = min(ans, j - i - 1);
        else break;
    }
    cout << ans << '\n';
    return 0;
}
