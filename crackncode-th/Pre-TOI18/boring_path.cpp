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

map<int, vector<t3>> mp;
int a[mxN], parent[mxN], mx[mxN];
ll ans[mxN];
int n;

int findParent(int child) {
    if(child == parent[child]) return child;
    return parent[child] = findParent(parent[child]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1, u, v, w; i <= n - 1; i++) {
        cin >> u >> v >> w; mp[w].emplace_back(u, v, i);
    }
    for(int i = 1; i <= n; i++) parent[i] = i, mx[i] = a[i];
    for(auto [w, edges] : mp) {
        for(auto [u, v, idx] : edges) {
            u = findParent(u), v = findParent(v);
            ans[idx] = 1ll * mx[u] * mx[v];
        }
        for(auto [u, v, idx] : edges) {
            u = findParent(u), v = findParent(v);
            if(u != v) parent[v] = u, mx[u] = max(mx[u], mx[v]);
        }
    }
    for(int i = 1; i <= n - 1; i++) cout << ans[i] << '\n'; 
    return 0;
}
