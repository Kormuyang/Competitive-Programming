#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 5e3 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<bool> vis(n + 1, false);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        int u = i, cnt = 0;
        do {
            vis[u] = true, u = a[u], cnt++;
        } while(u != i);
        if(cnt == 1) ans = max(ans, cnt);
        else if(cnt % 2 == 0) ans = 2;
        else {
            ans = 3; break;
        }
    }
    cout << ans << '\n';
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}
