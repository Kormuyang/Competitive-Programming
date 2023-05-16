#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t4 tuple<int, int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 3e2 + 2;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

vector<pi> res;
int n, m, x, ans = 0, curr = 0;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1, a, b; i <= m; i++) {
        cin >> a >> b; res.emplace_back(a, 1); res.emplace_back(b + 1, -1);
    }
    res.emplace_back(1, 0); res.emplace_back(n + 1, 0);
    sort(res.begin(), res.end());
    char c; cin >> c; x = (c == 'R' ? 0 : (c == 'G' ? 1 : 2));
    for(int i = 0; i < sz(res) - 1; i++) {
        curr = (curr + res[i].second) % 3;
        ans += ((3 - curr + x) % 3) * (res[i + 1].first - res[i].first);
    }
    cout << ans << '\n';
    return 0;
}
