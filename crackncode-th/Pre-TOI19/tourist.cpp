#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t4 tuple<int, int, int, int>

const int mxN = 1e5 + 1;

int a[mxN], sz[mxN], cnt[mxN], parent[mxN], ans[mxN];
pi e[mxN];
t4 req[mxN];
map<int, int> mp;
int n, m, k, q;

int findParent(int u) {
    if(u == parent[u]) return u;
    return parent[u] = findParent(parent[u]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k >> q;
    for(int i = 1, x; i <= k; i++) cin >> x, a[x]++;
    for(int i = 1; i < mxN; i++) if(a[i]) sz[a[i]]++, mp[a[i]];
    int idx = 0;
    for(auto &[x, y] : mp) y = ++idx;
    for(int i = 1; i <= m; i++) {
        auto &[u, v] = e[i]; cin >> u >> v;
    }
    for(int i = 1; i <= q; i++) {
        auto &[t, x, y, z] = req[i]; cin >> t >> x >> y; if(t == 1) cin >> z;
    }
    for(auto [val, idx] : mp) {
        iota(parent + 1, parent + n + 1, 1);
        for(int i = 1; i <= q; i++) {
            auto &[t, x, y, z] = req[i]; cnt[x] += (t == 1 and y <= val and val <= z);
        }
        for(int i = 1; i <= m; i++) if(cnt[i] == 0) {
            int u = findParent(e[i].first), v = findParent(e[i].second);
            if(u != v) parent[v] = u;
        }
        for(int i = q; i >= 1; i--) {
            auto &[t, x, y, z] = req[i];
            if(t == 1 and y <= val and val <= z) {
                if(--cnt[x] == 0) {
                    int u = findParent(e[x].first), v = findParent(e[x].second);
                    if(u != v) parent[v] = u;
                }
            }
            else if(findParent(x) == findParent(y)) ans[i] += sz[val];
        }
    }
    for(int i = 1; i <= q; i++) {
        auto &[t, x, y, z] = req[i];
        if(t == 2) cout << ans[i] << '\n';
    }
    return 0;
}
