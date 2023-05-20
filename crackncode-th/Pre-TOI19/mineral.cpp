#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int mxN = 1e5 + 1;

struct Fenwick {
    int t[mxN];
    void init() { for(int i = 0; i < mxN; i++) t[i] = 0; return; }
    void add(int idx, int val) { for(; idx < mxN; idx += (idx & -idx)) t[idx] += val; return; }
    int read(int idx) { int ret = 0; for(; idx > 0; idx -= (idx & -idx)) ret += t[idx]; return ret; }
} f;

int a[mxN], b[mxN];
int n, m, ans;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] *= 1000;
    for(int i = 1; i <= n; i++) cin >> b[i];
    int l = 0, r = 1e7;
    for(int cnt = 0; cnt < 50; cnt++) {
        int md = (l + r) / 2;
        vector<ll> qs(n + 1), v(n + 1);
        for(int i = 1; i <= n; i++) v[i] = qs[i] = qs[i - 1] + a[i] - 1ll * b[i] * md;
        sort(v.begin(), v.end());
        f.init();
        ll res = 0;
        for(int i = 0; i <= n; i++)  {
            int idx = lower_bound(v.begin(), v.end(), qs[i]) - v.begin() + 1;
            res += f.read(idx); f.add(idx, 1);
        }
        if(res >= m) ans = md, l = md + 1;
        else r = md - 1;
    }
    cout << fixed << setprecision(3) << ans / 1000.0 << '\n';
    return 0;
}
