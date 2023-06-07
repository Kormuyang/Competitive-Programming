#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mxN = 5e5 + 1;
const int MOD = 1e9 + 7;

vector<int> adj[mxN];
int fac[mxN];
int ans = 1;

void dfs(int u, int p) {
    int cnt = 0;
    for(auto v : adj[u]) if(v != p) {
        dfs(v, u); cnt++;
    }
    ans = (ans * fac[cnt]) % MOD;
    return;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    fac[0] = 1; for(int i = 1; i < mxN; i++) fac[i] = (fac[i - 1] * i) % MOD;
    int n; cin >> n; int prv; cin >> prv;
    for(int i = 0, x; i < 2 * (n - 1); i++) { cin >> x; adj[prv].emplace_back(x); prv = x; }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}
