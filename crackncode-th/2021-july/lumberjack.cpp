#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t5 tuple<int, int, int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

ll qs[mxN];
vector<ll> res;
ll n, k;

struct fenwick {
    ll t[mxN];
    void add(int idx, int val) { for(; idx <= mxN; idx += (idx & -idx)) t[idx] += val; return; }
    ll read(int idx) { ll ret = 0; for(; idx >= 1; idx -= (idx & -idx)) ret += t[idx]; return ret; }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> qs[i]; qs[i] += qs[i - 1];
        res.emplace_back(qs[i]); res.emplace_back(qs[i] - k);
    }
    res.emplace_back(0);
    sort(res.begin(), res.end());
    for(ll i : res) cout << i << ' ';
    return 0;
}
