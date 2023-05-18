#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 1e5 + 1;
const int mxM = 1e6 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

t3 edges[mxM];
int p[mxN], parent[mxN];
int n, m, ans = 0;

int findParent(int child) {
    if(child == parent[child]) return child;
    return parent[child] = findParent(parent[child]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    cin >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v; edges[i] = {p[u] + p[v], u, v};
    }
    sort(edges + 1, edges + m + 1); iota(parent + 1, parent + n + 1, 1);
    for(int i = 1; i <= m; i++) {
        auto [w, u, v] = edges[i];
        u = findParent(u), v = findParent(v);
        if(u != v) {
            parent[v] = u; ans += w;
        }
    }
    cout << ans << '\n';
    return 0;
}
