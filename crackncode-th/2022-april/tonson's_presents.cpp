#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int cnt[mxN];
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, x; i <= n; i++) {
        cin >> x; cnt[x]++;
    }
    for(int i = mxN - 2; i >= 1; i--) cnt[i] += cnt[i + 1];
    for(int i = 1; i <= m; i++) {
        ll ans = 0;
        for(int j = i; j < mxN; j += i) ans += cnt[j];
        cout << ans << '\n';
    }
    return 0;
}
