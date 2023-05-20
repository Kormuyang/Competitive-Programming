#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int mxN = 1e5 + 1;
const int mxR = 5e3 + 1;

t3 a[mxN];
int qs[mxR][mxR];
int n, m, r, c, ans;

int calc(int x1, int y1, int x2, int y2) {
    x1 = max(x1, 1), y1 = max(y1, 1), x2 = min(x2, r), y2 = min(y2, c);
    return qs[x2][y2] - qs[x2][y1 - 1] - qs[x1 - 1][y2] + qs[x1 - 1][y1 - 1];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++) {
        auto &[x, y, z] = a[i]; cin >> x >> y >> z;
    }
    for(int i = 1, x, y; i <= m; i++) {
        cin >> x >> y; qs[x][y] = 1;
    }
    for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++) {
        qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
    }
    for(int i = 1; i <= n; i++) {
        auto &[x, y, z] = a[i];
        while(calc(x - ans, y - ans, x + ans, y + ans) < z) ans++;
    }
    cout << ans << '\n';
    return 0;
}
