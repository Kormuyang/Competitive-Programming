#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int mxN = 2e5 + 2;

vector<int> adj[mxN];
char a[mxN];
bool vis[mxN];
queue<pi> q;
queue<int> res[26];
int n, m, k, ans;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v; adj[u].emplace_back(v); adj[v].emplace_back(u);
    }
    q.emplace(0, 1); vis[1] = true;
    while(!q.empty()) {
        auto [d, u] = q.front(); q.pop();
        res[a[u] - 'A'].emplace(d);
        for(auto v : adj[u]) if(!vis[v]) {
            vis[v] = true; q.emplace(d + 2, v);
        }
    }
    for(int i = 1; i <= k; i++) {
        char c; cin >> c;
        if(res[c - 'A'].empty()) {
            cout << "-1\n"; return 0;
        }
        ans += res[c - 'A'].front(); res[c - 'A'].pop();
    }
    cout << ans << '\n';
    return 0;
}
