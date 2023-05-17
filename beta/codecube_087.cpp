#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 1e5 + 1;

unordered_map<int, int> cnt;
int n, m; ll ans = 0;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        if(x <= m) ans += cnt[m - x];
        cnt[x]++;
    }
    cout << ans << '\n';
    return 0;
}
